NAME = letsgo
CC = c++
SRCS = Account.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = Account.hpp
FLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) tests.cpp -o $(NAME)

%.o:%.cpp $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all