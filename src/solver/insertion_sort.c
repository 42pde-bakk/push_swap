//
// Created by peerdebakker on 28-06-21.
//

#include "vector.h"
#include "operations.h"

static void	do_operation(t_vector* operations, t_collection* coll, const t_opcode op)
{
	vector_pushback(operations, op);
	execute_operation(op, coll);
}

void	insertion_sort(t_collection* coll, t_vector* ops)
{
	t_opcode op;

	while (!sort_is_done(coll))
	{
		if (get_node_value(coll->a->top->prev) < get_node_value(coll->a->top))
			op = SA;
		else
			op = RA;
		do_operation(ops, coll, op);
	}
}
