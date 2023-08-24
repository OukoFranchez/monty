#include "monty.h"

void monty_rotl(stack_t **stack_ptr, unsigned int line_no);
void monty_rotr(stack_t **stack_ptr, unsigned int line_no);
void monty_stack(stack_t **stack_ptr, unsigned int line_no);
void monty_queue(stack_t **stack_ptr, unsigned int line_no);

/**
 * monty_rotl - Rotates top value of stack_t linked list to the bottom.
 * @stack_ptr: pointer to top node of stack_t linked list.
 * @line_no: current working line no. of Monty bytecodes file.
 */
void monty_rotl(stack_t **stack_ptr, unsigned int line_no)
{
	stack_t *top, *bottom;

	if ((*stack_ptr)->next == NULL || (*stack_ptr)->next->next == NULL)
		return;

	top = (*stack_ptr)->next;
	bottom = (*stack_ptr)->next;

	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack_ptr;
	(*stack_ptr)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;
	(void)line_no;
}

/**
 * monty_rotr - Rotates the bottom value of a stack_t linked list to the top.
 * @stack_ptr: pointer to top node of stack_t linked list.
 * @line_no: current working line no. of Monty bytecodes file.
 */
void monty_rotr(stack_t **stack_ptr, unsigned int line_no)
{
	stack_t *top, *bottom;

	if ((*stack_ptr)->next == NULL || (*stack_ptr)->next->next == NULL)
		return;

	top = (*stack_ptr)->next;
	bottom = (*stack_ptr)->next;

	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack_ptr)->next = bottom;
	bottom->prev = *stack_ptr;
	bottom->next = top;
	top->prev = bottom;
	(void)line_no;
}

/**
 * monty_stack - Converts queue to stack_ptr.
 * @stack_ptr: pointer to top node of stack_t linked list.
 * @line_no: current working line no. of Monty bytecodes file.
 */
void monty_stack(stack_t **stack_ptr, unsigned int line_no)
{
	(*stack_ptr)->n = STACK;
	(void)line_no;
}

/**
 * monty_queue - Converts stack to queue.
 * @stack_ptr: pointer to top node of stack_t linked list.
 * @line_no: current working line no. of Monty bytecodes file.
 */
void monty_queue(stack_t **stack_ptr, unsigned int line_no)
{
	(*stack_ptr)->n = QUEUE;
	(void)line_no;
}
