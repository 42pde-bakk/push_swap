//
// Created by Peer De bakker on 3/29/21.
//

#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "stack.h"

typedef enum e_opcode
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}t_opcode;

typedef void	(*t_operation)();

void	execute_operation(t_opcode opcode, t_collection *collection);

void	sa(t_collection *collection);
void	sb(t_collection *collection);
void	ss(t_collection *collection);
void	pa(t_collection *collection);
void	pb(t_collection *collection);
void	ra(t_collection *collection);
void	rb(t_collection *collection);
void	rr(t_collection *collection);
void	rra(t_collection *collection);
void	rrb(t_collection *collection);
void	rrr(t_collection *collection);

#endif //OPERATIONS_H