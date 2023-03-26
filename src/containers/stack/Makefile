NAME					= stack.a

STACK_SRCS				= stack.cpp
STACK_OBJS				= $(patsubst %.cpp, %.o, $(STACK_SRCS))
STACK_INCLUDES			= stack.h

CC						= clang++
CFLAGS					= -Werror -Wall -Wextra -std=c++17
AR						= ar -rcs

%.o:		$(STACK_SRCS) $(STACK_INCLUDES)
	    $(CC) -c $(CFLAGS) $< -o $@

$(NAME):	$(STACK_OBJS) $(STACK_INCLUDES)
	    $(AR) $(NAME) $(STACK_INCLUDES) $(STACK_OBJS)
	    ranlib $(NAME)
	    make clean

all: $(NAME)

clean:
	rm -f $(STACK_OBJS)

fclean: clean
	@rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
