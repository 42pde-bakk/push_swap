//
// Created by peerdebakker on 13-07-21.
//

#include "stack.h"

static size_t	max(const size_t a, const size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

size_t	get_max_element(const t_stack *stack)
{
	t_stacknode	*temp;
	size_t		max_elem;

	max_elem = 0;
	temp = stack->top;
	while (temp)
	{
		max_elem = max(max_elem, temp->sorted_pos);
		temp = temp->prev;
	}
	return (max_elem);
}
