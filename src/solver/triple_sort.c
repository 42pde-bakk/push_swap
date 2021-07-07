//
// Created by peerdebakker on 06-07-21.
//

#include "stack.h"
#include "solver.h"
#include <unistd.h>

static size_t	get_chunk_size(t_stack *stack)
{
	if (stack->size <= 10)
		return (2);
	return (stack->size / 2);
}

void	triple_sort(t_collection *stacks)
{
	const unsigned int	totalsize = stacks->a->size;
	size_t				currentstack_size;
	size_t				rots;

	while (!sort_is_done(stacks))
	{
//		dprintf(2, "totalsize is %u, first is %u, second is %u\n", totalsize, totalsize / 2, totalsize / 4);
		currentstack_size = stacks->a->size;
		rots = 0;
		while (rots < currentstack_size)
		{
			if (stacks->a->top->sorted_pos < totalsize / 3)
			{
				/* Push to bottom of stack B */
				execute_and_print(PB, stacks);
				execute_and_print(RB, stacks);
			}
			else if (stacks->a->top->sorted_pos < 2 * totalsize / 3)
			{
				/* Push to top of stack B */
				execute_and_print(PB, stacks);
			}
			else
			{
				/* Push to bottom of stack A */
				execute_and_print(RA, stacks);
			}
			print_stacks(stacks);

			++rots;
		}
		break ;
	}
}

static bool	is_within(const size_t item, const size_t lower, const size_t upper)
{
	return (lower <= item && item < upper);
}

void	chunk_sort(t_collection *stacks)
{
	const size_t	chunk_size = get_chunk_size(stacks->a);
	const size_t	chunk_amounts = 4;
	size_t			bottom_chunk_marker;
	size_t			upper_chunk_marker;
	size_t			bottom_chunk_fill;
	size_t			upper_chunk_fill;

	bottom_chunk_fill = 0;
	upper_chunk_fill = 0;
	upper_chunk_marker = chunk_amounts / 2;
	bottom_chunk_marker = chunk_amounts / 2 - 1;

	while (!stack_is_empty(stacks->a))
	{
		if (is_within(stacks->a->top->sorted_pos, upper_chunk_marker * chunk_size, (upper_chunk_marker + 1) * chunk_size))
		{
			execute_and_print(PB, stacks);
			upper_chunk_fill++;
			if (upper_chunk_fill % chunk_size == 0)
				upper_chunk_marker++;
		}
		else if (is_within(stacks->a->top->sorted_pos, bottom_chunk_marker * chunk_size, (bottom_chunk_marker + 1) * chunk_size))
		{
			execute_and_print(PB, stacks);
			if (upper_chunk_fill > 0)
				execute_and_print(RB, stacks);
			bottom_chunk_fill++;
			if (bottom_chunk_fill % chunk_size == 0)
				bottom_chunk_marker--;
		} else {
			execute_and_print(RA, stacks);
		}
	}
	while (!stack_is_empty(stacks->b))
	{
		execute_and_print(PA, stacks);
		if (stacks->a->size > 1 && stacks->a->top->data > stacks->a->top->prev->data)
			execute_and_print(SA, stacks);
	}
	print_stacks(stacks);
}
