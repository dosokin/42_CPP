NAME = convert
SRCS = main.cpp ScalarConverter.cpp utils.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = ScalarConverter.hpp utils.h
CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all