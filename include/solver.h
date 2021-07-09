//
// Created by peerdb on 02-04-21.
//

#ifndef SOLVER_H
# define SOLVER_H

# include "vector.h"
# include "stack.h"

//void	indiansort(t_collection *collection);
t_vector	*radix_sort(t_collection *coll);
t_vector	*chunk_sort(t_collection *stacks);
t_vector	*smol_sort(t_collection *stacks);

void	set_sorted_pos(t_collection *coll);
size_t	get_chunk_size(t_stack *stack);

bool	is_within_chunk(size_t item, size_t chunk_nb, size_t chunk_size);
size_t	find_steps(size_t to_find, t_stacknode *startnode);
void	add_operation(t_opcode op, t_collection *stacks, t_vector *operations);

void	optimize_instructions(t_vector *ops);
void	print_all_operations(const t_vector *operations);


#endif //SOLVER_H
