//
// Created by Peer De bakker on 3/29/21.
//

#include "stack.h"
#include "libft.h"
#include "utils.h"

t_collection	*create_stacks(void)
{
	t_collection	*out;

	out = (t_collection *)ft_calloc(1, sizeof(t_collection));
	if (out == NULL)
		fatal_error("Error allocating memory for stack collection");
	out->a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!out->a)
		fatal_error("Error allocating memory for stack A");
	out->b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!out->b)
		fatal_error("Error allocating memory for stack B");
	return (out);
}

void	delete_stack(t_stack *stack)
{
	while (stack->size > 0)
		stack_pop(stack);
	free(stack);
	stack = NULL;
}
