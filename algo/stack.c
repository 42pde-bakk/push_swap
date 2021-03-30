//
// Created by Peer De bakker on 3/29/21.
//

#include "stack.h"
#include "libft.h"
#include "utils.h"

// function to create a stack of given capacity. It initializes size of
// stack as 0
t_stack	*create_stack()
{
	t_stack	*out;

	out = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!out)
		fatal_error("Error allocating memory for new stack");
	return (out);
}

void	*delete_stack(t_stack* stack)
{
	while (stack->size > 0)
		stack_pop(stack);
	free(stack);
	stack = NULL;
	return (NULL);
}

int	stack_is_empty(const t_stack *stack)
{
	return (stack->top == NULL);
}

static t_stacknode *new_node(int data)
{
	t_stacknode *node;

	node = (t_stacknode *)ft_calloc(1, sizeof(t_stacknode));
	if (!node)
		fatal_error("Error allocating memory for new stacknode");
	node->data = data;
	return (node);
}

// Function to add an item to stack. It increases size by 1
void	stack_push(t_stack *stack, int item)
{
	t_stacknode *node;

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

int	stack_duplicate_check(const t_stack* stack, int item)
{
	t_stacknode	*tmp;

	tmp = stack->bottom;
	while (tmp)
	{
		if (tmp->data == item)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	print_stacks(const t_stack *a, const t_stack *b)
{
	t_stacknode	*tmp_a;
	t_stacknode	*tmp_b;
	int fd;

	tmp_a = a->top;
	tmp_b = b->top;
	fd = STDOUT_FILENO;
	dprintf(fd, "A\t|\tB\n");
	while (tmp_a || tmp_b)
	{
		if (tmp_a) {
			ft_putnbr_fd(tmp_a->data, fd);
			tmp_a = tmp_a->prev;
		}
		if (tmp_b) {
			ft_putnbr_fd(tmp_b->data, fd);
			tmp_b = tmp_b->prev;
		}
		ft_putchar_fd('\n', fd);
	}
}
