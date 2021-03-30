//
// Created by Peer De bakker on 3/29/21.
//

#include "libft.h"
#include "push_swap.h"

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

t_stack	*parse_array(t_stack* stack_a, char** argv, int i) {
	int item;

	while (argv[i]) {
		if (!is_valid_arg(argv[i])) {
			delete_stack(stack_a);
			fatal_error("Error");
		}
		item = ft_atoi(argv[i]);
		if (stack_duplicate_check(stack_a, item)) {
			delete_stack(stack_a);
			fatal_error("Error");
		}
		stack_push(stack_a, ft_atoi(argv[i]));
		++i;
	}
	return (stack_a);
}

int main(int argc, char** argv) {
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = create_stack();
	stack_b = create_stack();
	if (argc == 1)
		fatal_error("Error");
	else if (argc == 2)
		stack_a = parse_array(stack_a, ft_split(argv[1], ' '), 0);
	else
		stack_a = parse_array(stack_a, argv, 1);
	print_stacks(stack_a, stack_b);
	execute_operation(&rotate, "ra", stack_a, NULL);
	execute_operation(&push, "pb", stack_b, stack_a);
	print_stacks(stack_a, stack_b);
	delete_stack(stack_a);
	delete_stack(stack_b);
	return (0);
}