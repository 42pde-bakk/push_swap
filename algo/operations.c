//
// Created by Peer De bakker on 3/29/21.
//

#include "operations.h"
#include "../libft/libft.h"

void	swap(t_stack *a) {
	int tmp;

	tmp = a->top->data;
	if (a->size > 1) {
		a->top->data = a->top->prev->data;
		a->top->prev->data = tmp;
	}
}

void	ss(t_stack *a, t_stack *b) {
	swap(a);
	swap(b);
}

// for pa -> t_stack *a,   t_stack *b
// for pb -> t_stack *b,   t_stack *a
void	push(t_stack *put, t_stack *take)
{
	if (take->size > 0) {
		stack_push(put, stack_pop(take));
	}
}

void	rotate(t_stack *stack)
{
	t_stacknode	*tmp;

	tmp = stack->top->prev;
	stack->bottom->prev = stack->top;
	stack->top->next = stack->bottom;
	stack->bottom = stack->top;
	tmp->next = NULL;
	stack->bottom->prev = NULL;
	stack->top = tmp;
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	reverse_rotate(t_stack *stack)
{
	t_stacknode	*tmp;

	tmp = stack->bottom->next;
	stack->top->next = stack->bottom;
	stack->bottom->prev = stack->top;
	stack->bottom->next = NULL;
	stack->top = stack->bottom;
	stack->bottom = tmp;
	tmp->prev = NULL;
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	execute_operation(void (*f)(), const char* operation, t_stack *arg1, t_stack *arg2)
{
	ft_putendl_fd(operation, STDOUT_FILENO);
	if (f == &swap || f == &rotate || f == &reverse_rotate)
		f(arg1);
	else
		f(arg1, arg2);
}