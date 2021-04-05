//
// Created by Peer De bakker on 3/29/21.
//

#include "stack.h"
#include "push_swap.h"
#include "solver.h"

int	main(int argc, char **argv)
{
	t_collection	*coll;

	coll = create_stacks();
	if (argc == 1)
		fatal_error("Error");
	else if (argc == 2)
		parse_split_array(coll, argv[1]);
	else
		parse_array(coll, argv, 1);
	bogosort(coll);
	return (cleanup(coll));
}
