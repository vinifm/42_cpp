NAME	= a.out
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

# valgring flags
LFLAGS	= --leak-check=full \
			--show-leak-kinds=all \
			--trace-children=yes \
			--track-origins=yes \
			./$(NAME)

# Directories
OBJDIR	= ./objs/
SRCDIR	= ./srcs/
INCLUDE	= -I ./include/

# Files
SRC		= main.cpp Animal.cpp Dog.cpp Cat.cpp WrongCat.cpp WrongAnimal.cpp
OBJ		= $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJDIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

leaks:
	valgrind $(LFLAGS)

run:
	@make --silent
	@./$(NAME)

.PHONY: all clean fclean re leaks run
