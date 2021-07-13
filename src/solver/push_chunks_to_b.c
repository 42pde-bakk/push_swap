//
// Created by peerdebakker on 13-07-21.
//

#include "solver.h"
#include "chunk.h"


void	push_chunks_to_b(t_collection *stacks, t_vector *operations, \
const int CHUNK_SIZE, const int CHUNK_AMOUNT)
{
	t_chunk	upper_chunk;
	t_chunk	lower_chunk;
	size_t	upper_fill;
	size_t	lower_fill;

	upper_chunk = chunk_init(CHUNK_AMOUNT / 2, CHUNK_SIZE);
	lower_chunk = chunk_init(CHUNK_AMOUNT / 2 - 1, CHUNK_SIZE);
	upper_fill = 0;
	lower_fill = 0;
	while (!stack_is_empty(stacks->a))
	{
		if (is_within_chunk((int)stacks->a->top->sorted_pos, &upper_chunk))
		{
			add_operation(PB, stacks, operations);
			++upper_fill;
			if (upper_fill % CHUNK_SIZE == 0)
				++(upper_chunk.nb);
		}
		else if (is_within_chunk((int)stacks->a->top->sorted_pos, &lower_chunk))
		{
			add_operation(PB, stacks, operations);
			if (upper_fill > 0 || lower_chunk.nb != CHUNK_AMOUNT / 2 - 1)
				add_operation(RB, stacks, operations);
			++lower_fill;
			if (lower_fill % CHUNK_SIZE == 0)
				--(lower_chunk.nb);
		}
		else
		{
			add_operation(RA, stacks, operations);
		}
	}
}
