//
// Created by peerdebakker on 13-07-21.
//

#include "solver.h"
#include "utils.h"

void	sync_up(t_collection *stacks, t_vector *ops)
{
	while (stacks->a->bottom->sorted_pos < stacks->a->top->sorted_pos)
		add_operation(RRA, stacks, ops);
}

void	push_logic(t_collection *stacks, t_vector *ops, ssize_t steps, const ssize_t *max_element)
{
	const t_opcode ROT_DIR = get_rotation_direction(stacks->b, &steps);

	while (stacks->b->top->sorted_pos != *max_element)
	{
		if (stacks->b->top->sorted_pos == *max_element - 1) {
			add_operation(PA, stacks, ops);
			continue;
		}
		add_operation(ROT_DIR, stacks, ops);
	}
	add_operation(PA, stacks, ops);
	if (stacks->a->size > 1 && stacks->a->top->sorted_pos == stacks->a->top->prev->sorted_pos + 1)
	{
		add_operation(SA, stacks, ops);
	}
}

void	push_chunk_to_a(t_collection *stacks, t_vector *operations, const ssize_t min_element, ssize_t max_element)
{
	ssize_t steps;

	while (max_element >= min_element)
	{
		steps = find_steps(max_element, stacks->b->top);
		if (steps >= 0)
			push_logic(stacks, operations, steps, &max_element);
		--max_element;
	}
//	sync_up(stacks, operations);
}

void	push_back_to_a(t_collection *stacks, t_vector *operations, const size_t CHUNK_SIZE, const size_t CHUNK_AMOUNT)
{
	int	current_chunk;

	current_chunk = (int)CHUNK_AMOUNT - 1;
	while (current_chunk >= 0)
	{
		push_chunk_to_a(stacks, operations, (ssize_t)(current_chunk * CHUNK_SIZE), (ssize_t)get_max_element(stacks->b));
		--current_chunk;
	}
}
