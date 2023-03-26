TESTS = tests
IGNORE_ERROR = || true

PROJECT_DIR				= ../src
PROJECT_LIB_DIR			= $(PROJECT_DIR)/lib
PROJECT_GRAPH_LIB		= $(PROJECT_LIB_DIR)/s21_graph.a
PROJECT_ALGOS_LIB		= $(PROJECT_LIB_DIR)/s21_graph_algorithms.a
PROJECT_LIBS			= $(PROJECT_GRAPH_LIB) $(PROJECT_ALGOS_LIB)
PROJECT_GRAPH_HDR_DIR	= $(PROJECT_DIR)/graph/includes/
PROJECT_GRAPH_INFS_DIR	= $(PROJECT_DIR)/graph/interfaces/
PROJECT_ALGOS_HDR_DIR	= $(PROJECT_DIR)/graph_algorithms/includes/
PROJECT_INCLUDES		= -I$(PROJECT_GRAPH_HDR_DIR) -I$(PROJECT_GRAPH_INFS_DIR) -I$(PROJECT_ALGOS_HDR_DIR)

TESTS_DIR				= unitTests
TESTS_SRCS				= $(shell find $(TESTS_DIR) -name "*.cpp")
TESTS_GRAPH_HEADERS		= $(TESTS_DIR)/graph/mocks
TESTS_ALGOS_HEADERS		= $(TESTS_DIR)/graph_algorithms/mocks
TESTS_INCLUDES			= -I$(TESTS_GRAPH_HEADERS) -I$(TESTS_ALGOS_HEADERS)
TESTS_OBJS				= $(patsubst %.cpp, %.o, $(TESTS_SRCS))
TESTS_DFILES			= $(patsubst %.cpp, %.d, $(TESTS_SRCS))

ALL_OBJECTS				= $(PROJECT_LIBS) $(TESTS_OBJS)

GTEST_DIR				= dependencies
GTEST_DIR_REPOSITORY	= $(GTEST_DIR)/googletest
GTEST_HEADERS_DIR		= $(GTEST_DIR_REPOSITORY)/googletest/include/gtest
GTEST_INCLUDES			= -I$(GTEST_HEADERS_DIR)
GTEST_LIB				= $(GTEST_DIR)/lib/libgtest_main.a $(GTEST_DIR)/lib/libgtest.a

GMOCK_DIR				= dependencies
GMOCK_HEADERS_DIR		= $(GTEST_DIR_REPOSITORY)/googlemock/include/gmock
GMOCK_INCLUDES			= -I$(GMOCK_HEADERS_DIR)
GMOCK_LIB				= $(GTEST_DIR)/lib/libgmock_main.a $(GTEST_DIR)/lib/libgmock.a

GTEST_BUILD				= $(GTEST_LIB) $(GMOCK_LIB)

CPPFLAGS += -isystem
CXXFLAGS += -g -Wall -Wextra -pthread -std=c++17 #-fsanitize=address,undefined -fno-sanitize-recover -fstack-protector -O0

all: $(GTEST_BUILD) run

leaks: $(GTEST_BUILD) run_leaks

$(GTEST_BUILD):
	@cd $(GTEST_DIR_REPOSITORY); \
	mkdir -p build && cd build; \
	cmake .. && make && make install; \
	mv lib ../.. >/dev/null 2>&1 || cd ../..

clean:
	@rm -f $(TESTS_OBJS) $(TESTS_DFILES)
	@cd $(PROJECT_DIR) && $(MAKE) clean

fclean: clean
	@rm -f $(TESTS)
	@rm -rf $(GTEST_DIR)/lib $(GTEST_DIR_REPOSITORY)/build
	@cd $(PROJECT_DIR) && $(MAKE) fclean

re: fclean all

%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(GTEST_INCLUDES) $(GMOCK_INCLUDES) $(PROJECT_INCLUDES) $(TESTS_INCLUDES) $< -o $@ -MMD

$(PROJECT_LIBS):
	cd $(PROJECT_DIR) && $(MAKE) libs

$(TESTS): $(ALL_OBJECTS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(ALL_OBJECTS) $(GTEST_LIB) $(TESTS_INCLUDES) $(GMOCK_LIB) $(GTEST_INCLUDES) $(GMOCK_INCLUDES) -o $@

run : $(TESTS)
	./$(TESTS) $(IGNORE_ERROR)
	$(MAKE) clean

run_leaks : $(TESTS)
	leaks --atExit -- ./$(TESTS) $(IGNORE_ERROR)
	$(MAKE) clean

include $(wildcard $(TESTS_DFILES))

.PHONY: all leaks clean fclean re coverage build_gtest run
