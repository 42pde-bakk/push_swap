//
// Created by peerdb on 03-07-21.
//

#include "stack.h"
#include "solver.h"
#include "vector.h"
#include "operations.h"
#include "utils.h"

size_t	get_max_rotations(const t_stack *stack, const size_t shift_bits_amount)
{
	size_t		rots;
	t_stacknode	*node;

	node = stack->bottom;
	rots = 1;
	while (node != stack->top)
	{
		if (((node->sorted_pos >> shift_bits_amount) & 1) == 1)
			return (rots);
		++rots;
		node = node->next;
	}
	return (stack->size);
}

void	radix_sort(t_collection *coll)
{
	const size_t	size = coll->a->size;
	const size_t	max_bits = get_max_bits(size - 1);
	size_t			i;
	size_t			j;

	set_sorted_pos(coll);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((coll->a->top->sorted_pos >> i) & 1) == 1)
				execute_and_print(RA, coll);
			else
				execute_and_print(PB, coll);
			++j;
		}
		while (!stack_is_empty(coll->b))
			execute_and_print(PA, coll);
		if (sort_is_done(coll))
			break ;
		++i;
	}
}
