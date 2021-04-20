//
// Created by peerdb on 02-04-21.
//

#include "stack.h"
#include "operations.h"
#include <stdlib.h>
#include <unistd.h>

void	bogosort(t_collection *collection)
{
	while (!stack_is_sorted(collection))
	{
		execute_operation(rand() %  RRR, collection);
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
		execute_operation(RR, coll);
	else if (rot_a)
		execute_operation(RA, coll);
	else if (rot_b)
		execute_operation(RB, coll);
	return (rot_a || rot_b);
}

bool	check_pushes(t_collection *coll)
{
	if (op_is_possible(coll, PA) && (coll->a->size == 0 || coll->b->top->data < coll->a->top->data))
	{
		execute_operation(PA, coll);
		return (true);
	}
	if (op_is_possible(coll, PB) && (coll->b->size == 0 || coll->a->top->data < coll->b->top->data))
	{
		execute_operation(PB, coll);
		return (true);
	}
	return (false);
}

static int	get_max_element(const t_collection *coll)
{
	t_stacknode *tmp;

	tmp = coll->a->bottom;
	int max = tmp->data;
	while (tmp) {
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

void	indiansort(t_collection *coll)
{
	print_stacks(coll);
	while (!stack_is_sorted(coll))
	{
		if (coll->a->size > 0 && coll->a->top->data == get_max_element(coll))
			execute_operation(PB, coll);
		else
			execute_operation(RA, coll);
		print_stacks(coll);
		sleep(1);
		if (coll->a->size == 0) {
			while (coll->b->size)
				execute_operation(PA, coll);
		}
	}
}
