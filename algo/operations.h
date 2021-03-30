//
// Created by Peer De bakker on 3/29/21.
//

#ifndef PUSH_SWAP_OPERATIONS_H
# define PUSH_SWAP_OPERATIONS_H
# include "stack.h"

enum e_op
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
};

typedef void (*t_operation)();

void	swap(t_stack *);
void	ss(t_stack *a, t_stack *b);
void	push(t_stack *, t_stack *);
void	rotate(t_stack *);
void	rr(t_stack *, t_stack *);
void	reverse_rotate(t_stack *);
void	rrr(t_stack *, t_stack *);
void	execute_operation(void (*f)(), const char* operation, t_stack *arg1, t_stack *arg2);

#endif //PUSH_SWAP_OPERATIONS_H
