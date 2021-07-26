//
// Created by peerdebakker on 09-07-21.
//

#include "stack.h"
#include "solver.h"
#include <unistd.h>
#include "chunk.h"

t_vector	*chunk_sort(t_collection *stacks)
{
	const int	chunk_size = get_chunk_size(stacks->a);
	const int	chunk_amounts = \
		((int)stacks->a->size + chunk_size - 1) / chunk_size;
	t_vector	*operations;

	operations = vector_init(chunk_size);
	if (sort_is_done(stacks))
		return (operations);
	push_chunks_to_b(stacks, operations, chunk_size, chunk_amounts);
	push_back_to_a(stacks, operations, (int)chunk_size, (int)chunk_amounts);
	return (operations);
}
