//
// Created by peerdebakker on 09-07-21.
//

#include "stack.h"
#include "solver.h"
#include <unistd.h>

t_vector	*chunk_sort(t_collection *stacks)
{
	const size_t	chunk_size = get_chunk_size(stacks->a);
	const size_t	chunk_amounts = (stacks->a->size + chunk_size - 1) / chunk_size;
	t_vector		*operations;

	dprintf(2, "chunk-size is %lu, amounts is %lu\n", chunk_size, chunk_amounts);
	operations = vector_init(chunk_size);
	push_chunks_to_b(stacks, operations, chunk_size, chunk_amounts);
	size_t			first_steps = operations->size;
	print_stacks(stacks);
	push_back_to_a(stacks, operations, chunk_size, chunk_amounts);
	dprintf(2, "It took %lu operations to push everythin to b, and then another %lu to push everything back to a\n", first_steps, operations->size - first_steps);
	print_stacks(stacks);
	return (operations);
}
