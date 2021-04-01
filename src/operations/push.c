//
// Created by peerdb on 31-03-21.
//

#include "stack.h"

static void	push(t_stack *put, t_stack *take)
{
	if (take->size > 0) {
		stack_push(put, stack_pop(take));
	}
}

void	pa(t_collection *collection)
{
	push(collection->a, collection->b);
}

void	pb(t_collection *collection)
{
	push(collection->b, collection->a);
}