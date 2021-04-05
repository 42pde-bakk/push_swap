NAME = push_swap checker
INCLUDE = -I ./libft/include -I ./include -Igetnextline/include -Ift_printf/include

SRC_DIR = ./src
STACK_DIR = $(SRC_DIR)/stack
OPERATIONS_DIR = $(SRC_DIR)/operations
CHECKER_DIR = $(SRC_DIR)/checker
SOLVER_DIR = $(SRC_DIR)/solver

UTILS = utils parsing
STACK_FILES = stack print_stacks stack_checks stack_operations
OP_FILES = operations push swap rotate reverse_rotate
CHECKER_FILES = checker
SOLVER_FILES = main bogosort

SRCS = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(UTILS))) \
		$(addprefix $(STACK_DIR)/, $(addsuffix .c, $(STACK_FILES))) \
		$(addprefix $(OPERATIONS_DIR)/, $(addsuffix .c, $(OP_FILES)))
CHECKER_SRCS = $(addprefix $(CHECKER_DIR)/, $(addsuffix .c, $(CHECKER_FILES)))
SOLVER_SRCS = $(addprefix $(SOLVER_DIR)/, $(addsuffix .c, $(SOLVER_FILES)))

OBJS = $(SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)
SOLVER_OBJS = $(SOLVER_SRCS:.c=.o)

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
#export DEBUG

all: $(NAME)

$(word 1, $(NAME)): $(OBJS) $(SOLVER_OBJS) libft.a getnextline.a ft_printf.a
	@$(CC) $(CFLAGS) $(OBJS) $(SOLVER_OBJS) libft/libft.a getnextline/getnextline.a ft_printf/libftprintf.a $(INCLUDE) -o $@
	@printf "$(PINK)Done building push_swap $(RESET)\n"

$(word 2, $(NAME)): $(OBJS) $(CHECKER_OBJS) libft.a getnextline.a ft_printf.a
	@$(CC) $(CFLAGS) $(OBJS) $(CHECKER_OBJS) libft/libft.a getnextline/getnextline.a ft_printf/libftprintf.a $(INCLUDE) -o $@
	@printf "$(PINK)Done building checker $(RESET)\n"

%.a: %
#	@echo -e "$(GREEN)Compiling $@ in directory $< $(RESET)"
	@make -sC $<

%.o: %.c
#	@echo -e "$(BLUE) Compiling file $< to $@ $(RESET)"
	@$(CC) -c $(CFLAGS) $(INCLUDE) $^ -o $@

clean:
	@/bin/rm -f *.o *~ *.gch
	@/bin/rm -f $(OBJS) $(CHECKER_OBJS) $(SOLVER_OBJS)
	@make clean -sC libft
	@make clean -sC getnextline
	@make clean -sC ft_printf

fclean:
	@/bin/rm -f *.o *~ *.gch
	@/bin/rm -f $(OBJS) $(CHECKER_OBJS) $(SOLVER_OBJS)
	@make fclean -sC libft
	@make fclean -sC getnextline
	@make fclean -sC ft_printf
	@/bin/rm -f $(NAME)

re: fclean all
