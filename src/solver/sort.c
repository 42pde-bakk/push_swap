//
// Created by peerdb on 02-04-21.
//

#include "stack.h"
#include "operations.h"
#include "solver.h"
#include <stdlib.h>
#include <unistd.h>

static int get_average(const t_stack *s)
{
	unsigned long long int	total;
	t_stacknode				*tmp;

	total = 0;
	tmp = s->bottom;
	while (tmp)
	{
		total += get_node_value(tmp);
		tmp = tmp->next;
	}
	return ((int)(total / s->size));
}

static int get_max(const t_stack *s)
{
	int			max;
	t_stacknode	*tmp;

	tmp = s->bottom;
	max = INT_MIN;
	while (tmp)
	{
		if (get_node_value(tmp) > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

static int get_min(const t_stack *s)
{
	int			min;
	t_stacknode	*tmp;

	tmp = s->bottom;
	min = INT_MAX;
	while (tmp)
	{
		if (get_node_value(tmp) < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

t_opcode	smart_rotate(t_stack *stack)
{
	t_stacknode *tmp;
	int			i;
	int			max;
	t_opcode	op;

	i = 0;
	max = get_max(stack);
	tmp = stack->top;
	while (tmp && tmp->data != max)
	{
		tmp = tmp->next;
		++i;
	}
	op = RA;
	if (i > (int)(stack->size / 2))
		op = RRA;
	return (op);
}

void	split_shit(t_collection *coll)
{
	int average;

	average = get_average(coll->a);
//	while (get_max(coll->a) > average)
	while (get_max(coll->a) > average && !stack_is_sorted(coll->a, 'a'))
	{
		if (get_node_value(coll->a->top) == get_max(coll->a))
			execute_and_print(PB, coll);
		else {
			execute_and_print(smart_rotate(coll->a), coll);
			// smart rotation
		}
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

static bool	makes_sense_to_swap(t_collection *coll)
{
	if (coll->a->size <= 1)
		return (false);
	if (get_node_value(coll->a->top->prev) < get_node_value(coll->a->bottom) && (get_node_value(coll->a->top->prev) >
		get_node_value(coll->a->top) || get_node_value(coll->a->top) > get_node_value(coll->a->bottom)))
	{
		execute_and_print(SA, coll);
		execute_and_print(RA, coll);
		return (true);
	}
	if (get_node_value(coll->a->top->prev) > get_node_value(coll->a->top))
	{
		execute_and_print(SA, coll);
		return (true);
	}
	return (false);
}

static void sort_a(t_collection *coll)
{
	while (!stack_is_sorted(coll->a, 'a'))
	{
		if (get_node_value(coll->a->top) == get_min(coll->a))
			execute_and_print(RA, coll);
		else if (get_node_value(coll->a->top) == get_max(coll->a))
			execute_and_print(PB, coll);
		else
			execute_and_print(smart_rotate(coll->a), coll);
	}
}

static void sort_b(t_collection *coll)
{
	while (!stack_is_sorted(coll->b, 'b'))
	{
		if (get_node_value(coll->b->top) == get_max(coll->b))
			execute_and_print(RB, coll);
		else if (get_node_value(coll->b->top) == get_min(coll->b))
			execute_and_print(PA, coll);
		else
			execute_and_print(smart_rotate(coll->b), coll);
	}
}

static void	stack_b_on_a(t_collection *coll)
{
	while (coll->b->size)
		execute_and_print(PA, coll);
}

void	indiansort(t_collection *coll)
{
	int	steps_to_max;

//	print_stacks(coll);
	split_shit(coll);
	sort_a(coll);
	dprintf(2, "laater\n");
	sort_b(coll);
	stack_b_on_a(coll);
	return;
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
			if (makes_sense_to_swap(coll)) {

			}
			else if (steps_to_max < 0)
				execute_and_print(RRA, coll);
			else
				execute_and_print(RA, coll);
		}
//			execute_and_print(RA, coll);
//		print_stacks(coll);
//		sleep(1);
	}
}
