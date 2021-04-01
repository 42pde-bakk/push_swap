//
// Created by peerdb on 31-03-21.
//

#include "stack.h"

static void	reverse_rotate(t_stack *stack)
{
	t_stacknode	*tmp;

	if (stack_is_empty(stack) || stack->size == 1)
		return ;
	tmp = stack->bottom->next;
	stack->top->next = stack->bottom;
	stack->bottom->prev = stack->top;
	stack->bottom->next = NULL;
	stack->top = stack->bottom;
	stack->bottom = tmp;
	tmp->prev = NULL;
}

void	rra(t_collection *collection)
{
	reverse_rotate(collection->a);
}

void	rrb(t_collection *collection)
{
	reverse_rotate(collection->b);
}

void	rrr(t_collection *collection)
{
	reverse_rotate(collection->a);
	reverse_rotate(collection->b);
}
