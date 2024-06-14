NAME = serializer
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Serializer.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
HEADERS = Serializer.hpp

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all