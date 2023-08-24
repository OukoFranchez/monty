#include "monty.h"
#include <string.h>

/**
 * freeStack - Frees a stack_t stack
 * @stack: A pointer to the top of the stack
 *         or bottom of queue of stack_t
 */

void freeStack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * initStack - initializes a stack_t stack with beginning
 *              stack and ending queue nodes
 * @stack: Pointer to an uninitialized stack
 * Return: If an error occurs - EXIT_FAILURE
 *         Otherwise - EXIT_SUCCESS
 */

int initStack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (mallocError());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * checkMode - Checks if linked list is in stack or queue mode
 * @stack: pointer to the top of stack or bottom of queue
 *
 * Return: If stack is in Stack mode - STACK (0)
 *         If stack is in queue mode - QUEUE (1)
 *         Otherwise - 2
 */

int checkMode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
