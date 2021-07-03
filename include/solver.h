//
// Created by peerdb on 02-04-21.
//

#ifndef SOLVER_H
# define SOLVER_H

# include "vector.h"

//void	indiansort(t_collection *collection);
void	insertion_sort(t_collection *coll, t_vector *ops);
void	radix_sort(t_collection *coll);
void	set_sorted_pos(t_collection* coll);

void	execute_and_print(t_opcode op, t_collection *coll);

#endif //SOLVER_H
