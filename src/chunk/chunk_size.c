//
// Created by peerdebakker on 14-07-21.
//

#include "stack.h"

int	get_chunk_size(t_stack *stack)
{
	if (stack->size <= 5)
		return (2);
	if (stack->size <= 10)
		return ((int)stack->size / 3);
	if (stack->size <= 50)
		return ((int)stack->size / 10);
	if (stack->size < 100)
		return (8);
	if (stack->size < 150)
		return (8);
	return (25);
}
