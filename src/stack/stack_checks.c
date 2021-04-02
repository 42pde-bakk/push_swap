//
// Created by peerdb on 02-04-21.
//

#include "stack.h"

bool	stack_duplicate_check(const t_stack *stack, int item)
{
	t_stacknode	*tmp;

	tmp = stack->bottom;
	while (tmp)
	{
		if (tmp->data == item)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

bool	stack_is_empty(const t_stack *stack)
{
	return (stack->top == NULL);
}

bool	stack_is_sorted(const t_collection *coll)
{
	t_stacknode	*tmp;

	if (!stack_is_empty(coll->b))
		return (false);
	tmp = coll->a->bottom;
	while (tmp->next)
	{
		if (tmp->next->data < tmp->data)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}
