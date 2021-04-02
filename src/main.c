//
// Created by Peer De bakker on 3/29/21.
//

#include "libft.h"
#include "stack.h"
#include "push_swap.h"
#include "checker.h"
#include "solver.h"
#include <stdio.h>

static int	cleanup(t_collection *coll)
{
	delete_stack(coll->a);
	delete_stack(coll->b);
	free(coll);
	return (0);
}

#ifdef CHECKER
static void	start_loop(t_collection *coll)
{
	printf("checker defined and is %d\n", CHECKER);
	checker(coll);
}
#else
static void	start_loop(t_collection *coll)
{
	printf("checker IS NOT defined\n");
	bogosort(coll);
}
#endif

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
	print_stacks(coll);
	start_loop(coll);
	return (cleanup(coll));
}
