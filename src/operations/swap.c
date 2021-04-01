//
// Created by peerdb on 31-03-21.
//

#include "stack.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->top->data;
	if (stack->size > 1)
	{
		stack->top->data = stack->top->prev->data;
		stack->top->prev->data = tmp;
	}
}

void	sa(t_collection *collection)
{
	swap(collection->a);
}

void	sb(t_collection *collection)
{
	swap(collection->b);
}

void	ss(t_collection *collection)
{
	sa(collection);
	sb(collection);
}
