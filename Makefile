NAME = ircserv

CC = clang++

# FLAGS = -g -fsanitize=address -Wall -Werror -Wextra -std=c++98
FLAGS = -g -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp \

OBJS = $(SRCS:.cpp=.o)

DEPS = $(SRCS:.cpp=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.cpp Makefile
	$(CC) $(FLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
