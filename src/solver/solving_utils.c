//
// Created by peerdebakker on 22-04-21.
//

#include "operations.h"
#include "vector.h"
#include <unistd.h>

void	add_operation(const t_opcode op, t_collection *stacks, t_vector *ops)
{
	vector_pushback(ops, op);
	print_operation(op, STDERR_FILENO);
	execute_operation(op, stacks);
}

t_opcode	get_rotation_direction(const t_stack *stack, ssize_t *steps)
{
	if (*steps > stack->size / 2)
	{
		*steps = stack->size - *steps;
		if (stack->id == 'a')
			return (RRA);
		return (RRB);
	}
	if (stack->id == 'a')
		return (RA);
	return (RB);
}

size_t	get_chunk_size(t_stack *stack)
{
	if (stack->size <= 5)
		return (2);
	if (stack->size <= 10)
		return (stack->size / 3);
	if (stack->size <= 50)
		return (stack->size / 10);
	if (stack->size < 100)
		return (8);
	if (stack->size < 150)
		return (8);
	return (25);
}

bool	is_within_chunk(const size_t item, const size_t chunk_nb, \
const size_t chunk_size)
{
	return (item / chunk_size == chunk_nb);
}

ssize_t	find_steps(const size_t to_find, t_stacknode *startnode)
{
	ssize_t	steps;

	steps = 0;
	while (startnode)
	{
		if (startnode->sorted_pos == to_find)
			return (steps);
		++steps;
		startnode = startnode->prev;
	}
	return (-1);
}

void	print_all_operations(const t_vector *operations)
{
	size_t	i;

	i = 0;
	while (i < operations->size)
	{
		print_operation(operations->arr[i], STDOUT_FILENO);
		++i;
	}
}
