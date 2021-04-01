NAME = push_swap
INCLUDE = -I ./libft -I ./includes -Igetnextline -Ift_printf

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

$(NAME): $(OBJS) libft.a getnextline.a ft_printf.a
	@echo -e "$(BLUE)Bundling"
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a getnextline/getnextline.a ft_printf/libftprintf.a $(INCLUDE) -o $@
	@echo -e "$(PINK)Done $(RESET)"

%.a: %
	@echo -e "$(GREEN)Compiling $@ in directory $< $(RESET)"
	@make -sC $<

%.o: %.c
	@echo -e "$(BLUE) Compiling file $< to $@ $(RESET)"
	$(CC) -c $(CFLAGS) $(INCLUDE) $^ -o $@

clean:
	@/bin/rm -f *.o *~ *.gch
	@/bin/rm -f $(OBJS)
	@make clean -sC libft
	@make clean -sC getnextline
	@make clean -sC ft_printf

fclean: clean
	@make fclean -sC libft
	@make fclean -sC getnextline
	@make fclean -sC ft_printf
	@/bin/rm -f $(NAME)

re: fclean all