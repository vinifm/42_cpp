NAME	= convert
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
INCLUDE	= ./include/

# Files
SRC		= main.cpp \
			ScalarConverter.cpp \
			ScalarConverter_detect.cpp \
			ScalarConverter_exceptions.cpp \
			ScalarConverter_print.cpp

OBJ		= $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(NAME): $(OBJDIR) $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

leaks:
	valgrind $(LFLAGS)

test:
	@./test.sh all

.PHONY: all clean fclean re leaks test
