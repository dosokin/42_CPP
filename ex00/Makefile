NAME = whatever
SRCS = main.cpp
HEADERS = whatever.hpp
CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

all : $(NAME)

$(NAME) :
	$(CC) $(FLAGS) main.cpp -o $(NAME)

clean :
	rm -rf main.o

fclean : clean
	rm -rf $(NAME)

re : fclean all
