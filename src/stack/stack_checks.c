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

int	get_node_value(const t_stacknode *node)
{
	if (!node)
		return (INT_MIN);
	return (node->data);
}

bool	stack_is_empty(const t_stack *stack)
{
	return (stack->top == NULL);
}

bool	sort_is_done(const t_collection* coll)
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

static bool	stack_is_reverse_sorted(const t_stack *stack, const char id)
{
	t_stacknode	*tmp;

	(void)id;
	if (stack_is_empty(stack))
		return (true);
	tmp = stack->bottom;
	while (tmp->next)
	{
		if (tmp->next->data > tmp->data)
			return (false);
		tmp = tmp->next;
	}
	return (true);

}

bool	stack_is_sorted(const t_stack *stack, const char id)
{
	t_stacknode	*tmp;

	if (id == 'b')
		return (stack_is_reverse_sorted(stack, id));
	if (stack_is_empty(stack))
		return (true);
	tmp = stack->bottom;
	while (tmp->next)
	{
		if (tmp->next->data < tmp->data)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}
