//
// Created by peerdb on 02-04-21.
//

#include "stack.h"
#include "operations.h"
#include <stdlib.h>

void	bogosort(t_collection *collection)
{
	while (!stack_is_sorted(collection))
	{
		execute_operation(rand() %  RRR, collection);
	}
}