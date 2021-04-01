NAME = push_swap
INCLUDE = -I ./libft -I ./includes

SRC_DIR = ./src
OPERATIONS_DIR = $(SRC_DIR)/operations

FILES = main stack utils
OP_FILES = operations push swap rotate reverse_rotate

SRCS = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES))) \
		$(addprefix $(OPERATIONS_DIR)/, $(addsuffix .c, $(OP_FILES)))
OBJS = $(SRCS:.c=.o)

# COLORS
PINK = \x1b[35;01m
BLUE = \x1b[34;01m
YELLOW = \x1b[33;01m
GREEN = \x1b[32;01m
RED = \x1b[31;01m
WHITE = \x1b[31;37m
RESET = \x1b[0m

CFLAGS = -Wall -Werror -Wextra
ifdef DEBUG
 CFLAGS += -g -fsanitize=address
else
 CFLAGS += -Ofast
endif

all: $(NAME)

$(NAME): $(OBJS)
	@echo -e "$(YELLOW)Making libft.a"
	@make -sC ./libft
	@echo -e "$(BLUE)Bundling"
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME) $(INCLUDE)
	@echo -e "$(PINK)Done $(RESET)"

%.o: %.c
	@echo -e "$(BLUE) Compiling file $< to $@ $(RESET)"
	$(CC) -c $(CFLAGS) $(INCLUDE) $^ -o $@

clean:
	@/bin/rm -f *.o *~ *.gch
	@/bin/rm -f $(OBJS)
	@make clean -sC ./libft

fclean: clean
	@make fclean -sC ./libft
	@/bin/rm -f libft.a
	@/bin/rm -f $(NAME)

re: fclean all