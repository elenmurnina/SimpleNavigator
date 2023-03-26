NAME					= queue.a

QUEUE_SRCS				= queue.cpp
QUEUE_OBJS				= $(patsubst %.cpp, %.o, $(QUEUE_SRCS))
QUEUE_INCLUDES			= queue.h

CC						= clang++
CFLAGS					= -Werror -Wall -Wextra -std=c++17
AR						= ar -rcs

%.o:		$(QUEUE_SRCS) $(QUEUE_INCLUDES)
	    $(CC) -c $(CFLAGS) $< -o $@

$(NAME):	$(QUEUE_OBJS) $(QUEUE_INCLUDES)
	    $(AR) $(NAME) $(QUEUE_INCLUDES) $(QUEUE_OBJS)
	    ranlib $(NAME)
	    make clean

all: $(NAME)

clean:
	rm -f $(QUEUE_OBJS)

fclean: clean
	@rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
