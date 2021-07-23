//
// Created by peerdb on 03-07-21.
//

#include "stack.h"
#include "solver.h"
#include "vector.h"

static unsigned int	get_max_bits(const unsigned int max_num)
{
	unsigned int	max_bits;

	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	return (max_bits);
}

/* Credit where credit is due:
 * https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
*/

t_vector	*radix_sort(t_collection *coll)
{
	const size_t	size = coll->a->size;
	const size_t	max_bits = get_max_bits(size - 1);
	t_vector		*ops;
	size_t			i;
	size_t			j;

	i = 0;
	ops = vector_init(size);
	while (i < max_bits && !sort_is_done(coll))
	{
		j = 0;
		while (j < size)
		{
			if (((coll->a->top->sorted_pos >> i) & 1) == 1)
				add_operation(RA, coll, ops);
			else
				add_operation(PB, coll, ops);
			++j;
		}
		while (!stack_is_empty(coll->b))
			add_operation(PA, coll, ops);
		++i;
	}
	return (ops);
}
