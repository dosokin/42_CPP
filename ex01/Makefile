NAME = form_and_bureaucrat
SRCS = Bureaucrat.cpp Form.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = Bureaucrat.hpp Form.hpp
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