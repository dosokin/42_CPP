NAME = array
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
HEADERS = Array.hpp Array.tpp

all : $(NAME)

$(NAME) :
	$(CC) $(FLAGS) main.cpp -o $(NAME)

clean :
	rm -rf main.o

fclean : clean
	rm -rf $(NAME)

re : fclean all