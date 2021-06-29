//
// Created by peerdb on 02-04-21.
//

// Function to add an item to stack. It increases size by 1

#include "libft.h"
#include "utils.h"
#include "stack.h"

static t_stacknode	*new_node(int data)
{
	t_stacknode	*node;

	node = (t_stacknode *)ft_calloc(1, sizeof(t_stacknode));
	if (!node)
		fatal_error("Error allocating memory for new stacknode");
	node->data = data;
	return (node);
}

void	stack_push(t_stack *stack, int item)
{
	t_stacknode	*node;

	node = new_node(item);
	if (stack->size == 0)
		stack->bottom = node;
	else
	{
		stack->top->next = node;
		node->prev = stack->top;
	}
	stack->top = node;
	stack->size++;
}

void	stack_push_under(t_stack *stack, int item)
{
	t_stacknode	*node;

	node = new_node(item);
	if (stack->size == 0)
		stack->top = node;
	else
	{
		stack->bottom->prev = node;
		node->next = stack->bottom;
	}
	stack->bottom = node;
	stack->size++;
}

// Function to remove an item from stack. It decreases size by 1

int	stack_pop(t_stack *stack)
{
	int			out;
	t_stacknode	*tmp;

	if (stack_is_empty(stack))
		return (INT_MIN);
	out = stack->top->data;
	tmp = stack->top;
	stack->top = tmp->prev;
	if (stack->top)
		stack->top->next = NULL;
	free(tmp);
	tmp = NULL;
	--stack->size;
	return (out);
}

// Function to return the top from stack without removing it

int	stack_peek(const t_stack *stack)
{
	if (stack_is_empty(stack))
		return (INT_MIN);
	return (stack->top->data);
}

