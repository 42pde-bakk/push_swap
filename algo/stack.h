//
// Created by Peer De bakker on 3/29/21.
//

#ifndef STACK_H
# define STACK_H
# include <stdlib.h>
# include <limits.h>
#include <stdio.h>

typedef struct s_stacknode
{
	int					data;
	struct s_stacknode	*prev;
	struct s_stacknode	*next;
}t_stacknode;

typedef struct s_stack
{
	unsigned int	size;
	t_stacknode		*top;
	t_stacknode		*bottom;
}t_stack;

t_stack	*create_stack();
void	*delete_stack(t_stack* stack);
//int		stack_is_full(const t_stack *stack);
int			stack_duplicate_check(const t_stack* stack, int item);
int		stack_is_empty(const t_stack *stack);
void	stack_push(t_stack *stack, int item);
int		stack_pop(t_stack *stack);
int		stack_peek(const t_stack *stack);
void	print_stacks(const t_stack *a, const t_stack *b);

#endif //STACK_H
