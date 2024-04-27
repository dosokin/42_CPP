NAME = a.out
SRCS = AMateria.cpp Cure.cpp Ice.cpp main.cpp Character.cpp MateriaSource.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = AMateria.hpp Cure.hpp Ice.hpp ICharacter.hpp Character.hpp IMateriaSource.hpp MateriaSource.hpp
CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS)

%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
