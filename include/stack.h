//
// Created by Peer De bakker on 3/29/21.
//

#ifndef STACK_H
# define STACK_H
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>

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

typedef struct s_collection
{
	unsigned int	max_amount_digits;
	t_stack			*a;
	t_stack			*b;
}t_collection;

t_collection	*create_stacks(void);
void			delete_stack(t_stack *stack);
bool			stack_is_sorted(const t_collection *coll);
bool			stack_duplicate_check(const t_stack *stack, int item);
bool			stack_is_empty(const t_stack *stack);
void			stack_push(t_stack *stack, int item);
int				stack_pop(t_stack *stack);
int				stack_peek(const t_stack *stack);
void			print_stacks(const t_collection *stacks);

#endif //STACK_H