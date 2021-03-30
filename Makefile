NAME = push_swap

SRC_DIR = ./algo
PRINTF_DIR = ./ft_printf

SRC = main.c \
	stack.c \
	operations.c \
	utils.c

FILES = $(addprefix $(SRC_DIR)/, $(SRC))
# COLORS
PINK = \x1b[35;01m
BLUE = \x1b[34;01m
YELLOW = \x1b[33;01m
GREEN = \x1b[32;01m
RED = \x1b[31;01m
WHITE = \x1b[31;37m
RESET = \x1b[0m

FLAGS = -Wall -Werror -Wextra
ifdef DEBUG
 FLAGS += -g -fsanitize=address
else
 FLAGS += -Ofast
endif

all: $(NAME)

$(NAME): $(FILES)
	@echo -e "$(YELLOW)Making libft.a"
	@make -sC ./libft
	@echo -e "$(BLUE)Bundling"
	@$(CC) $(FLAGS) $(FILES) libft/libft.a -o $(NAME) -I libft
	@echo -e "$(PINK)Done"

clean:
	@/bin/rm -f *.o *~ *.gch
	@make clean -sC ./libft

fclean: clean
	@make fclean -sC ./libft
	@/bin/rm -f libft.a
	@/bin/rm -f $(NAME)

re: fclean all