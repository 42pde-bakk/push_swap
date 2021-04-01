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

void	parse_array(t_collection *coll, char** argv, int i) {
	int				item;
	unsigned int	digits_amount;

	while (argv[i]) {
		if (!is_valid_arg(argv[i])) {
			delete_stack(coll->a);
			fatal_error("Error");
		}
		item = ft_atoi(argv[i]);
		digits_amount = amount_digits(item);
		if (stack_duplicate_check(coll->a, item)) {
			delete_stack(coll->a);
			fatal_error("Error");
		}
		if (digits_amount > coll->max_amount_digits)
			coll->max_amount_digits = digits_amount;
		stack_push(coll->a, ft_atoi(argv[i]));
		++i;
	}
}

int	cleanup(t_collection *coll)
{
	delete_stack(coll->a);
	delete_stack(coll->b);
	free(coll);
	coll = 0;
	return (0);
}

int main(int argc, char** argv) {
	t_collection	*coll;
	coll = create_stacks();
	if (argc == 1)
		fatal_error("Error");
	else if (argc == 2)
		parse_array(coll, ft_split(argv[1], ' '), 0);
	else
		parse_array(coll, argv, 1);
	print_stacks(coll);
	execute_operation(RA, coll);
//	execute_operation(&push, "pb", stack_b, stack_a);
	print_stacks(coll);
	return (cleanup(coll));
}