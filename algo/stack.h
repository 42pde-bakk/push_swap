//
// Created by Peer De bakker on 3/29/21.
//

#ifndef STACK_H
# define STACK_H
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				top;
	unsigned int	capacity;
	int				*array;
}t_stack;

t_stack	*create_stack(unsigned int capacity);
int		stack_is_full(const t_stack *stack);
int		stack_is_empty(const t_stack *stack);
void	stack_push(t_stack *stack, int item);
int		stack_pop(t_stack *stack);
int		stack_peek(const t_stack *stack);

#endif //STACK_H
