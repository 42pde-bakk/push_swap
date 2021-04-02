//
// Created by peerdb on 02-04-21.
//

#include "stack.h"
#include "operations.h"
#include <stdlib.h>
#include <unistd.h>

void	bogosort(t_collection *collection)
{
	while (!stack_is_sorted(collection))
	{
		execute_operation(rand() %  RRR, collection);
	}
}

void	indiansort(t_collection *coll)
{
	print_stacks(coll);
	while (!stack_is_sorted(coll))
	{
//		int temp = stack_pop(coll->a);
		while (!stack_is_empty(coll->b) && stack_peek(coll->b) > stack_peek(coll->a)) {
			execute_operation(PB, coll);
		}
		
		print_stacks(coll);
		sleep(1);
	}
}