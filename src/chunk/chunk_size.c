//
// Created by peerdebakker on 14-07-21.
//

#include "stack.h"

static size_t	ft_sqrt(const size_t nb)
{
	size_t	counter;

	counter = 1;
	while (counter * counter <= nb)
	{
		++counter;
	}
	return (counter - 1);
}

int	get_chunk_size(t_stack *stack)
{
	return ((int)ft_sqrt(stack->size));
}
