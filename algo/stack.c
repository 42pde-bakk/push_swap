//
// Created by Peer De bakker on 3/29/21.
//

#include "stack.h"

// function to create a stack of given capacity. It initializes size of
// stack as 0
t_stack	*create_stack(unsigned int capacity)
{
	t_stack	*out;

	out = (t_stack *)malloc(sizeof(t_stack));
	out->capacity = capacity;
	out->top = -1;
	out->array = (int *)malloc(out->capacity * sizeof(int));
	return (out);
}

// Stack is full when top is equal to the last index
int	stack_is_full(const t_stack *stack)
{
	return (stack->top == stack->capacity - 1);
}

// Stack is empty when top is equal to -1
int	stack_is_empty(const t_stack *stack)
{
	return (stack->top == -1);
}

// Function to add an item to stack.  It increases top by 1
void	stack_push(t_stack *stack, int item)
{
	if (!stack_is_full(stack))
	{
		++stack->top;
		stack->array[stack->top] = item;
	}
}

// Function to remove an item from stack.  It decreases top by 1
int	stack_pop(t_stack *stack)
{
	int	out;

	if (stack_is_empty(stack))
		return (INT_MIN);
	out = stack->array[stack->top];
	--stack->top;
	return (out);
}

// Function to return the top from stack without removing it
int	stack_peek(const t_stack *stack)
{
	if (stack_is_empty(stack))
		return (INT_MIN);
	return (stack->array[stack->top]);
}
