//
// Created by peerdb on 03-07-21.
//

#include "stack.h"
#include "solver.h"
#include "vector.h"
#include "operations.h"
#include "utils.h"

void	radix_sort(t_collection* coll)
{
	const unsigned int size = coll->a->size;
	const unsigned int max_bits = get_max_bits(size - 1);
	size_t i = 0, j;

	set_sorted_pos(coll);
	dprintf(2, "before while loop, max_bits is %u\n", max_bits);
	while (i < max_bits)
	{
		dprintf(2, "%zu/%u\n", i, max_bits);
		print_stacks(coll);
		j = 0;
		while (j < size)
		{
			unsigned int num = coll->a->top->sorted_pos;
//			dprintf(2, "num is %d, check is %d\n", num, (num >> i) & 1);
			// if (i + 1)-th bit is 1, leave it in stack A
			if (((num >> i)&1) == 1)
				execute_and_print(RA, coll);
			else
				execute_and_print(PB, coll);
			++j;
		}
		while (!stack_is_empty(coll->b))
			execute_and_print(PA, coll);
		++i;
	}
	printf("donezo11\n");
//	print_stacks(coll);
}
