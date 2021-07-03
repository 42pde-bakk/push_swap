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
		free(stack_pop(stack));
	free(stack);
	stack = NULL;
}

//t_collection *copy_stacks(const t_collection *stack) {
//	t_collection	*out;
//	t_stacknode		*tmp_old;
//
//	out = create_stacks();
//	tmp_old = stack->a->bottom;
//	while (tmp_old)
//	{
//		stack_push(out->a, tmp_old->data);
//		tmp_old = tmp_old->next;
//	}
//	tmp_old = stack->b->bottom;
//	while (tmp_old)
//	{
//		stack_push(out->b, tmp_old->data);
//		tmp_old = tmp_old->next;
//	}
//	return (out);
//}
