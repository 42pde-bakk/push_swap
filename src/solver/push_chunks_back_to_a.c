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

void	push_logic(t_collection *stacks, t_vector *ops, ssize_t steps)
{
	const t_opcode ROT_DIR = get_rotation_direction(stacks->b, &steps);

	while (steps > 0)
	{
		add_operation(ROT_DIR, stacks, ops);
		--steps;
	}
	add_operation(PA, stacks, ops);
}

void	push_chunk_to_a(t_collection *stacks, t_vector *operations, const size_t min_element, size_t max_element)
{
	ssize_t steps;

	steps = find_steps(max_element, stacks->b->top);
	dprintf(2, "min is %lu, max is %lu, steps is %zd\n", min_element, max_element, steps);
	while (steps >= 0 && max_element >= min_element)
	{
		dprintf(2, "max_elem is %lu, steps is %zd\n", max_element, steps);
//		dprintf(2, "in chunk loop, steps is %zd\n", steps);
		push_logic(stacks, operations, steps);
		--max_element;
		steps = find_steps(max_element, stacks->b->top);
	}
	sync_up(stacks, operations);
}

void	push_back_to_a(t_collection *stacks, t_vector *operations, const size_t CHUNK_SIZE, const size_t CHUNK_AMOUNT)
{
	int	current_chunk;

	current_chunk = (int)CHUNK_AMOUNT - 1;
	while (current_chunk >= 0)
	{
		dprintf(2, "in push_back_to_a loop\n");
		push_chunk_to_a(stacks, operations, current_chunk * CHUNK_SIZE, get_max_element(stacks->b));
		--current_chunk;
	}
}
