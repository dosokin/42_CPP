NAME = iter
HEADER = iter.hpp
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) :
	$(CC) $(FLAGS) main.cpp -o $(NAME)

clean :
	rm -rf main.o

fclean : clean
	rm -rf $(NAME)

re : fclean all