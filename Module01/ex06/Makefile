CC = g++
CFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98
MAKEFLAGS += --silent

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
EXECUTABLE = harlFilter

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
		$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re