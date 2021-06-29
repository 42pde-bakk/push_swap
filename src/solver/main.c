//
// Created by Peer De bakker on 3/29/21.
//

#include "stack.h"
#include "push_swap.h"
#include "solver.h"
#include "vector.h"
#include "libft.h"

static void	print_operation(const t_opcode opcode)
{
	static const char			*op_stringcodes[] = {
			[SA] = "sa", [SB] = "sb", [SS] = "ss",
			[PA] = "pa", [PB] = "pb",
			[RA] = "ra", [RB] = "rb", [RR] = "rr",
			[RRA] = "rra", [RRB] = "rrb", [RRR] = "rrr", [ERROR] = "Error"
	};

	if (opcode != ERROR)
		ft_putendl_fd(op_stringcodes[opcode], STDOUT_FILENO);
}

static void	print_operations(const t_vector* operations)
{
	size_t	i;

	i = 0;
	while (i < operations->size)
	{
		print_operation(operations->arr[i]);
		++i;
	}
}

int	main(int argc, char **argv)
{
	t_collection	*coll;
	t_vector		*operations;

	coll = create_stacks();
	if (argc == 1)
		fatal_error("Error");
	else if (argc == 2)
		parse_split_array(coll, argv[1]);
	else
		parse_array(coll, argv, 1);
	operations = vector_init(coll->a->size);
	insertion_sort(coll, operations);
//	optimize(coll);
	print_operations(operations);
//	vector_destroy(operations);
	vector_destroy(operations);
	return (cleanup(coll));
}
