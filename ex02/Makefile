NAME = form_and_bureaucrat
SRCS = Bureaucrat.cpp AForm.cpp main.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = Bureaucrat.hpp AForm.hpp
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
	rm -rf *_shrubbery

re : fclean all