//
// Created by peerdebakker on 06-07-21.
//

#include "stack.h"
#include "solver.h"
#include <unistd.h>

static size_t	get_chunk_size(t_stack *stack)
{
	if (stack->size <= 10)
		return (3);
	return (stack->size / 10);
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

static bool	is_within_chunk(const size_t item, const size_t chunk_nb, const size_t chunk_size)
{
	return (item / chunk_size == chunk_nb);
}

static void	push_chunks_to_b(t_collection *stacks, const size_t CHUNK_SIZE, const size_t CHUNK_AMOUNT)
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
			execute_and_print(PB, stacks);
			++upper_fill;
			if (upper_fill % CHUNK_SIZE == 0)
				++upper_chunk;
		}
		else if (is_within_chunk(stacks->a->top->sorted_pos, lower_chunk, CHUNK_SIZE))
		{
			execute_and_print(PB, stacks);
			execute_and_print(RB, stacks);
			++lower_fill;
			if (lower_fill % CHUNK_SIZE == 0)
				--lower_chunk;
		}
		else
		{
			execute_and_print(RA, stacks);
		}
	}
}

size_t	find_steps(const size_t to_find, t_stacknode *startnode)
{
	size_t	steps;

	steps = 0;
	while (startnode && startnode->sorted_pos != to_find)
	{
		++steps;
		startnode = startnode->prev;
	}
	return (steps);
}

void	navigate_to(const size_t to_find, t_collection *stacks)
{
	size_t		steps;

	steps = find_steps(to_find, stacks->b->top);
	if (steps > stacks->b->size / 2) {
		steps = stacks->b->size - steps;
		while (steps != 0)
		{
			execute_and_print(RRB, stacks);
			--steps;
		}
	} else {
		while (steps != 0)
		{
			execute_and_print(RB, stacks);
			--steps;
		}
	}
}

void	push_back_to_a(t_collection *stacks, const size_t CHUNK_SIZE, const size_t CHUNK_AMOUNT)
{
	size_t	max_in_b;

	(void)CHUNK_AMOUNT;
	(void)CHUNK_SIZE;
	max_in_b = stacks->b->size - 1;
	while (!stack_is_empty(stacks->b))
	{
		navigate_to(max_in_b, stacks);
		execute_and_print(PA, stacks);
		--max_in_b;
	}
}

void	chunk_sort(t_collection *stacks)
{
	const size_t	chunk_size = get_chunk_size(stacks->a);
	const size_t	chunk_amounts = stacks->a->size / chunk_size;

	push_chunks_to_b(stacks, chunk_size, chunk_amounts);
	print_stacks(stacks);
	push_back_to_a(stacks, chunk_size, chunk_amounts);
	print_stacks(stacks);
}
