//
// Created by peerdb on 31-03-21.
//

#include "stack.h"

static void	rotate(t_stack *stack)
{
	t_stacknode	*tmp;

	tmp = stack->top->prev;
	stack->bottom->prev = stack->top;
	stack->top->next = stack->bottom;
	stack->bottom = stack->top;
	tmp->next = NULL;
	stack->bottom->prev = NULL;
	stack->top = tmp;
}

void	ra(t_collection *coll)
{
	rotate(coll->a);
}

void	rb(t_collection *coll)
{
	rotate(coll->b);
}

void	rr(t_collection *coll)
{
	rotate(coll->a);
	rotate(coll->b);
}

