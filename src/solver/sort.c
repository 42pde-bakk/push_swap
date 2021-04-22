//
// Created by peerdb on 02-04-21.
//

#include "stack.h"
#include "operations.h"
#include "solver.h"
#include <stdlib.h>
#include <unistd.h>

void	bogosort(t_collection *collection)
{
	while (!sort_is_done(collection))
	{
		execute_operation(rand() % RRR, collection);
	}
}

bool	op_is_possible(const t_collection *coll, const t_opcode op)
{
	if (op == SA)
		return (coll->a->size > 1);
	if (op == SB)
		return (coll->b->size > 1);
	if (op == SS)
		return (coll->a->size > 1 && coll->b->size > 1);
	if (op == PA)
		return (coll->b->size > 0);
	if (op == PB)
		return (coll->a->size > 0);
	if (op == RA || op == RRA)
		return (coll->a->size > 1);
	if (op == RB || op == RRB)
		return (coll->b->size > 1);
	if (op == RR || op == RRR)
		return (coll->a->size > 1 && coll->b->size > 1);
	return (false);
}

bool	check_rotations(t_collection *coll)
{
	bool	rot_a;
	bool	rot_b;

	rot_a = false;
	rot_b = false;
	if (coll->a->size > 1 && coll->a->top->data < coll->a->bottom->data)
		rot_a = true;
	if (coll->b->size > 1 && coll->b->top->data < coll->b->bottom->data)
		rot_b = true;
	if (rot_a && rot_b)
		execute_and_print(RR, coll);
	else if (rot_a)
		execute_and_print(RA, coll);
	else if (rot_b)
		execute_and_print(RB, coll);
	return (rot_a || rot_b);
}

bool	check_pushes(t_collection *coll)
{
	if (op_is_possible(coll, PA) && (coll->a->size == 0 || coll->b->top->data < coll->a->top->data))
	{
		execute_and_print(PA, coll);
		return (true);
	}
	if (op_is_possible(coll, PB) && (coll->b->size == 0 || coll->a->top->data < coll->b->top->data))
	{
		execute_and_print(PB, coll);
		return (true);
	}
	return (false);
}

static int	get_steps_to_max_elem(const t_collection *coll)
{
	t_stacknode *tmp;
	int			steps;
	int			max;
	int			i;

	tmp = coll->a->top;
	max = tmp->data;
	steps = 0;
	i = 0;
	while (tmp) {
		if (tmp->data > max) {
			max = tmp->data;
			steps = i;
		}
		tmp = tmp->prev;
		++i;
	}
	if ((size_t)steps > coll->a->size / 2)
		steps *= -1;
	return (steps);
}

void	indiansort(t_collection *coll)
{
	int	steps_to_max;

//	print_stacks(coll);
	while (!sort_is_done(coll))
	{
		steps_to_max = get_steps_to_max_elem(coll);
//		dprintf(2, "steps to max is %d\n", steps_to_max);
		if (coll->b->size && stack_is_sorted(coll->a, 'a') && stack_is_sorted(coll->b, 'b')) {
			execute_and_print(PA, coll);
		}
		else if (coll->a->size > 0 && steps_to_max == 0)
			execute_and_print(PB, coll);
		else
		{
			if (steps_to_max < 0)
				execute_and_print(RRA, coll);
			else
				execute_and_print(RA, coll);
		}
//			execute_and_print(RA, coll);
//		print_stacks(coll);
//		sleep(1);
	}
}
