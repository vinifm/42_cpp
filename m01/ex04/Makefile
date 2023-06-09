NAME	= replacer
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

# valgring flags
LFLAGS	= --leak-check=full \
			--show-leak-kinds=all \
			--trace-children=yes \
			--track-origins=yes \
			./$(NAME)

SRC		= main.cpp
TXT_FILES = infile.txt infile.txt.replace

OBJDIR	= ./objs/
OBJ		= $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJDIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TXT_FILES)

re: fclean all

leaks:
	valgrind $(LFLAGS)

run:
	@make --silent
	@./$(NAME)

test:
	@make --silent
	@$(CC) $(CFLAGS) test.cpp -o test
	@./test
	@$(RM) test

.PHONY: all clean fclean re leaks run test
