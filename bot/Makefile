NAME = ircbot

CC = c++

# FLAGS = -g -fsanitize=address -Wall -Werror -Wextra -std=c++98
OS = $(shell uname)
CFLAGS = -g -I/usr/include/kqueue -Wall -Werror -Wextra -std=c++98 
# LDFLAGS = $(if $(filter-out Linux,$(OS)),$(),$(-lkqueue))
ifeq ($(OS), Linux)
	LDFLAGS = -lkqueue
else
	LDFLAGS =
endif

SRCS = srcs/main.cpp \
	srcs/ClientSocket.cpp \
	srcs/ClientEngine.cpp \
	srcs/Color.cpp
	

OBJS = $(SRCS:.cpp=.o)

DEPS = $(SRCS:.cpp=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC)  $^ -o  $@ $(LDFLAGS)
	

%.o: %.cpp Makefile
	$(CC) $(CFLAGS) -MMD -MP -c  $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re