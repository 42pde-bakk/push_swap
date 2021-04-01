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

bool	stack_is_empty(const t_stack *stack)
{
	return (stack->top == NULL);
}

bool	stack_is_sorted(const t_collection *coll)
{
	t_stacknode	*tmp;

	if (!stack_is_empty(coll->b))
		return (false);
	tmp = coll->a->bottom;
	while (tmp->next)
	{
		if (tmp->next->data < tmp->data)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

static t_stacknode	*new_node(int data)
{
	t_stacknode	*node;

	node = (t_stacknode *)ft_calloc(1, sizeof(t_stacknode));
	if (!node)
		fatal_error("Error allocating memory for new stacknode");
	node->data = data;
	return (node);
}

// Function to add an item to stack. It increases size by 1

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

bool	stack_duplicate_check(const t_stack *stack, int item)
{
	t_stacknode	*tmp;

	tmp = stack->bottom;
	while (tmp)
	{
		if (tmp->data == item)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

void	print_stacks(const t_collection *stacks)
{
	int			fd;
	t_stacknode	*tmp_a;
	t_stacknode	*tmp_b;

//	clearscreen();
	tmp_a = stacks->a->top;
	tmp_b = stacks->b->top;
	fd = STDOUT_FILENO;
	dprintf(fd, "\nA\t|\tB\n\n");
	while (tmp_a || tmp_b)
	{
		if (tmp_a)
		{
			ft_putnbr_fd(tmp_a->data, fd);
			tmp_a = tmp_a->prev;
		}
		ft_putstr_fd("\t|\t", fd);
		if (tmp_b)
		{
			ft_putnbr_fd(tmp_b->data, fd);
			tmp_b = tmp_b->prev;
		}
		ft_putchar_fd('\n', fd);
	}
	ft_putchar_fd('\n', fd);
}
