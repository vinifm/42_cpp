NAME	= test
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

# valgring flags
LFLAGS	= --leak-check=full \
			--show-leak-kinds=all \
			--trace-children=yes \
			--track-origins=yes \
			--track-fds=yes

# Directories
OBJDIR	= ./objs/
INCLUDE	= -I ./include/

# Files
SRC		= basics.cpp Sample.class.cpp
OBJ		= $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

all: $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o: %.cpp
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJDIR) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

leaks:
	valgrind $(LFLAGS)

run:
	make re
	./$(NAME)

.PHONY: all clean fclean re leaks run
