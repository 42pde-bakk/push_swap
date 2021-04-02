NAME = push_swap checker
INCLUDE = -I ./libft -I ./includes -Igetnextline -Ift_printf

SRC_DIR = ./src
STACK_DIR = $(SRC_DIR)/stack
OPERATIONS_DIR = $(SRC_DIR)/operations
CHECKER_DIR = $(SRC_DIR)/checker
SOLVER_DIR = $(SRC_DIR)/solver

FILES = main utils parsing
STACK_FILES = stack print_stacks stack_checks stack_operations
OP_FILES = operations push swap rotate reverse_rotate
CHECKER_FILES = checker
SOLVER_FILES = bogosort

SRCS = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES))) \
		$(addprefix $(STACK_DIR)/, $(addsuffix .c, $(STACK_FILES))) \
		$(addprefix $(OPERATIONS_DIR)/, $(addsuffix .c, $(OP_FILES))) \
		$(addprefix $(CHECKER_DIR)/, $(addsuffix .c, $(CHECKER_FILES))) \
		$(addprefix $(SOLVER_DIR)/, $(addsuffix .c, $(SOLVER_FILES)))

OBJS = $(SRCS:.c=.o)

# COLORS
PINK = \x1b[35;01m
BLUE = \x1b[34;01m
YELLOW = \x1b[33;01m
GREEN = \x1b[32;01m
RED = \x1b[31;01m
WHITE = \x1b[31;37m
RESET = \x1b[0m

CFLAGS = -Wall -Werror -Wextra -pedantic
ifdef DEBUG
 CFLAGS += -g -fsanitize=address
else
 CFLAGS += -Ofast
endif

all: $(NAME)

$(word 1, $(NAME)): $(OBJS) libft.a getnextline.a ft_printf.a
	@echo "building push_swap"
	@$(CC) $(CFLAGS) -D CHECKER=0 $(OBJS) libft/libft.a getnextline/getnextline.a ft_printf/libftprintf.a $(INCLUDE) -o $@
	@echo -e "$(PINK)Done $(RESET)"

$(word 2, $(NAME)): $(OBJS) libft.a getnextline.a ft_printf.a
	@echo "building checker"
	@$(CC) $(CFLAGS) -D CHECKER=1 $(OBJS) libft/libft.a getnextline/getnextline.a ft_printf/libftprintf.a $(INCLUDE) -o $@
	@echo -e "$(PINK)Done $(RESET)"


%.a: %
	@#echo -e "$(GREEN)Compiling $@ in directory $< $(RESET)"
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
