//
// Created by peerdebakker on 13-07-21.
//

#include "solver.h"

void	push_chunks_to_b(t_collection *stacks, t_vector *operations, \
const size_t CHUNK_SIZE, const size_t CHUNK_AMOUNT)
{
	size_t			upper_chunk;
	size_t			lower_chunk;
	size_t			upper_fill;
	size_t			lower_fill;

	upper_chunk = CHUNK_AMOUNT / 2;
	lower_chunk = CHUNK_AMOUNT / 2 - 1;
	upper_fill = 0;
	lower_fill = 0;
	while (!stack_is_empty(stacks->a))
	{
		if (is_within_chunk(stacks->a->top->sorted_pos, upper_chunk, CHUNK_SIZE))
		{
			add_operation(PB, stacks, operations);
			++upper_fill;
			if (upper_fill % CHUNK_SIZE == 0)
				++upper_chunk;
		}
		else if (is_within_chunk(stacks->a->top->sorted_pos, lower_chunk, CHUNK_SIZE))
		{
			add_operation(PB, stacks, operations);
			if (upper_fill > 0 || lower_chunk != CHUNK_AMOUNT / 2 - 1)
				add_operation(RB, stacks, operations);
			++lower_fill;
			if (lower_fill % CHUNK_SIZE == 0)
				--lower_chunk;
		}
		else
		{
			add_operation(RA, stacks, operations);
		}
	}
}
