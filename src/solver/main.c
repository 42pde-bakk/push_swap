//
// Created by Peer De bakker on 3/29/21.
//

#include "stack.h"
#include "push_swap.h"
#include "solver.h"
#include "vector.h"

int	main(int argc, char **argv)
{
	t_collection	*coll;
	t_vector		*operations;
	int				i;

	coll = create_stacks();
	i = 1;
	if (argc == 1)
		return (cleanup(coll));
	while (i < argc)
	{
		parse_split_array(coll, argv[i]);
		++i;
	}
	set_sorted_pos(coll);
	if (coll->a->size <= 5)
		operations = smol_sort(coll);
	else
		operations = chunk_sort(coll);
	optimize_instructions(operations);
	print_all_operations(operations);
	vector_destroy(operations);
	return (cleanup(coll));
}
