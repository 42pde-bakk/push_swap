//
// Created by Peer De bakker on 3/29/21.
//

#include "../libft/libft.h"
#include "push_swap.h"

static void	fatal_error(const char* s)
{
	ft_putendl_fd(s, 2);
	exit(EXIT_FAILURE);
}

int	is_valid_arg(const char* s) {
	int i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] == '-' || s[i] == '+' || (s[i] >= '0' && s[i] <= '9')))
			return (0);
		++i;
	}
	return (1);
}

t_stack	*parse_array(char** argv, int i) {
	t_stack	*stack_a;
	int item;

	stack_a = create_stack();
	while (argv[i]) {
		if (!is_valid_arg(argv[i]))
			return (delete_stack(stack_a));
		item = ft_atoi(argv[i]);
		if (stack_duplicate_check(stack_a, item))
			return (delete_stack(stack_a));
		stack_push(stack_a, ft_atoi(argv[i]));
		++i;
	}
	return (stack_a);
}

int main(int argc, char** argv) {
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	(void)stack_b;
	if (argc == 1)
		fatal_error("Error");
	else if (argc == 2)
		stack_a = parse_array(ft_split(argv[1], ' '), 0);
	else
		stack_a = parse_array(argv, 1);
	if (!stack_a)
		fatal_error("Error");
	print_stack(stack_a);
	execute_operation(&rotate, "ra", stack_a, stack_b);
	print_stack(stack_a);
	return (0);
}