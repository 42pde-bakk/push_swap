//
// Created by peerdb on 13-07-21.
//

#include "chunk.h"

t_chunk	chunk_init(const int nb, const int size)
{
	const t_chunk	out = {
			.nb = (short)nb,
			.size = (short)size,
			.min = nb * size,
		 	.max = (nb + 1) * size - 1
	};

	return (out);
}

void	chunk_decrease(t_chunk *chunk)
{
	--chunk->nb;
	chunk->min = chunk->nb * chunk->size;
	chunk->max = chunk->min + chunk->size - 1;
}

bool	is_within_chunk(const int item, const t_chunk *chunk)
{
	return (item / chunk->size == chunk->nb);
//	return (chunk->min <= item && item <= chunk->max);
}

int get_chunk_size(t_stack *stack)
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
