//
// Created by Peer De bakker on 3/29/21.
//

#include "stack.h"
#include "push_swap.h"
#include "solver.h"
#include "vector.h"
#include "libft.h"

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
	set_sorted_pos(coll);
	if (coll->a->size <= 5)
	{
		dprintf(2, "gonna run smol_sort\n");
		operations = smol_sort(coll);
	}
	else
	{
		dprintf(2, "gonna run chunk_sort!\n");
	//	operations = radix_sort(coll);
		operations = chunk_sort(coll);
	}
	optimize_instructions(operations);
	print_all_operations(operations);
	vector_destroy(operations);
	return (cleanup(coll));
}
