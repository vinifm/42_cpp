NAME	= phonebook
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

# valgring flags
LFLAGS	= --leak-check=full \
			--show-leak-kinds=all \
			--trace-children=yes \
			--track-origins=yes \
			./$(NAME)

SRC		= phonebook.cpp
INCLUDE	= PhoneBook.class.hpp PhoneBook.class.cpp

OBJDIR	= ./objs/
OBJ		= $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

all: $(NAME)

$(OBJ): $(SRC) $(INCLUDE)
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

leaks:
	valgrind $(LFLAGS)

git:
	git add ../
	git commit -m"make git"
	git push

.PHONY: all clean fclean re leaks run
