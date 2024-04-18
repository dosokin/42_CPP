NAME = a.out
SRCS = main.cpp Fixed.cpp 
OBJS = $(SRCS:.cpp=.o)
HEADERS = Fixed.hpp
CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f a.out

re : fclean all
