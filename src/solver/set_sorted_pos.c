//
// Created by peerdb on 03-07-21.
//

#include "vector.h"
#include "stack.h"

t_vector	*dump_items(const t_collection *coll)
{
	t_vector	*vec;
	t_stacknode	*tmp;

	vec = vector_init(coll->a->size);
	tmp = coll->a->bottom;
	while (tmp)
	{
		vector_pushback(vec, tmp->data);
		tmp = tmp->next;
	}
	return (vec);
}

size_t	get_largest_positive_value(const t_collection *coll)
{
	t_stacknode	*tmp;
	int			max;

	max = 0;
	tmp = coll->a->bottom;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

size_t	get_smallest_negative_value(const t_collection *coll)
{
	t_stacknode	*tmp;
	int			min;

	min = 0;
	tmp = coll->a->bottom;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min * -1);
}

void	build_arrays_of_indices(t_vector *all_items, t_vector *neg_idxs,
								t_vector *pos_idxs, t_collection *coll)
{
	int			i;
	int			value;
	t_stacknode	*tmp;

	i = 0;
	while (i < all_items->size)
	{
		value = all_items->arr[i];
		if (value < 0)
			neg_idxs->arr[value * -1] = i;
		else
			pos_idxs->arr[value] = i;
		++i;
	}
	tmp = coll->a->bottom;
	while (tmp)
	{
		if (tmp->data < 0)
			tmp->sorted_pos = neg_idxs->arr[tmp->data * -1];
		else
			tmp->sorted_pos = pos_idxs->arr[tmp->data];
		tmp = tmp->next;
	}
}

void	set_sorted_pos(t_collection *coll)
{
	t_vector	*all_items;
	t_vector	*neg_indexes;
	t_vector	*pos_indexes;

	all_items = dump_items(coll);
	neg_indexes = vector_init(get_smallest_negative_value(coll));
	pos_indexes = vector_init(get_largest_positive_value(coll));
	vector_sort(all_items);
	build_arrays_of_indices(all_items, neg_indexes, pos_indexes, coll);
	vector_destroy(all_items);
	vector_destroy(neg_indexes);
	vector_destroy(pos_indexes);
}
