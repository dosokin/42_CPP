NAME = bipbipboup
SRCS = Contact.cpp PhoneBook.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = Contact.hpp Phonebook.hpp
CC = c++
FLAGS = -Werror -Wextra -Wall -std=c++98

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) main.cpp -o $(NAME)

%.o : %.cpp $(HEADERS)
	$(CC) $(FLAGS) -cpp $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all