//
// Created by peerdebakker on 09-07-21.
//

#include "vector.h"
#include "stack.h"
#include "solver.h"

static void	push_smallest_to_b(t_collection *stacks, t_vector *ops)
{
	const unsigned int	max = stacks->a->size;

	while (stacks->a->size > 3)
	{
		if (stacks->a->top->sorted_pos < max - 3)
			add_operation(PB, stacks, ops);
		else
			add_operation(RA, stacks, ops);
	}
}

static void	sort_three(t_collection *stacks, t_vector *ops)
{
	const unsigned int	max = stacks->a->size + stacks->b->size - 1;

	if (stack_is_sorted(stacks->a))
		return;
	if (stacks->a->top->sorted_pos == max)
		add_operation(RA, stacks, ops);
	else if (stacks->a->top->prev->sorted_pos == max)
		add_operation(RRA, stacks, ops);
	if (stacks->a->top->sorted_pos > stacks->a->top->prev->sorted_pos)
		add_operation(SA, stacks, ops);
}

static void	push_b_to_a(t_collection *stacks, t_vector *ops)
{
	while (!stack_is_empty(stacks->b))
	{
		if (stacks->b->size > 1 && \
		stacks->b->top->sorted_pos < stacks->b->top->prev->sorted_pos)
			add_operation(SB, stacks, ops);
		add_operation(PA, stacks, ops);
	}
}

t_vector	*smol_sort(t_collection *stacks)
{
	t_vector	*operations;

	operations = vector_init(stacks->a->size);
	push_smallest_to_b(stacks, operations);
	sort_three(stacks, operations);
	push_b_to_a(stacks, operations);
	return (operations);
}
