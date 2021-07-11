//
// Created by peerdebakker on 09-07-21.
//

#include "stack.h"
#include "solver.h"
#include <unistd.h>

bool	should_swap(const t_stack *s)
{
	if (s->size < 2)
		return false;
	if (s->id == 'a' && s->top->data > s->top->prev->data)
		return true;
	if (s->id == 'b' && s->top->data < s->top->prev->data)
		return true;
	return false;
}

static void	push_chunks_to_b(t_collection *stacks, t_vector *operations, const size_t CHUNK_SIZE, const size_t CHUNK_AMOUNT)
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

void	navigate_to(const size_t to_find, t_collection *stacks, t_vector *operations)
{
	size_t		steps;

	steps = find_steps(to_find, stacks->b->top);
	if (steps > stacks->b->size / 2) {
		steps = stacks->b->size - steps;
		while (steps != 0)
		{
			add_operation(RRB, stacks, operations);
			--steps;
		}
	} else {
		while (steps != 0)
		{
			if (steps == 1 && stacks->b->top->sorted_pos == to_find - 1)
				add_operation(SB, stacks, operations);
			else
				add_operation(RB, stacks, operations);
			--steps;
		}
	}
}

void	push_back_to_a(t_collection *stacks, t_vector *operations)
{
	size_t	max_in_b;

	max_in_b = stacks->b->size - 1;
	while (!stack_is_empty(stacks->b))
	{
		navigate_to(max_in_b, stacks, operations);
		add_operation(PA, stacks, operations);
		--max_in_b;
	}
}

t_vector	*chunk_sort(t_collection *stacks)
{
	const size_t	chunk_size = get_chunk_size(stacks->a);
	const size_t	chunk_amounts = (stacks->a->size + chunk_size - 1) / chunk_size;
	t_vector		*operations;

	dprintf(2, "chunk-size is %lu, amounts is %lu\n", chunk_size, chunk_amounts);
	operations = vector_init(chunk_size);
	push_chunks_to_b(stacks, operations, chunk_size, chunk_amounts);

	size_t	first_steps = operations->size;
	print_stacks(stacks);
	push_back_to_a(stacks, operations);
	dprintf(2, "It took %lu operations to push everythin to b, and then another %lu to push everything back to a\n", first_steps, operations->size - first_steps);

	return (operations);
}
