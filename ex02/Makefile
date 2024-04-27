NAME = animal
SRCS = AAnimal.cpp Dog.cpp Cat.cpp main.cpp WrongCat.cpp WrongAnimal.cpp Brain.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = AAnimal.hpp Dog.hpp Cat.hpp WrongCat.hpp WrongAnimals.hpp Brain.hpp
FLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
