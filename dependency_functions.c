#include "monty.h"

void monty_nop(stack_t **stack_ptr, unsigned int line_no);
void monty_pchar(stack_t **stack_ptr, unsigned int line_no);
void monty_pstr(stack_t **stack_ptr, unsigned int line_no);

/**
 * monty_nop - Does nothing for Monty opcode 'nop'.
 * @stack_ptr: pointer to top node of stack_t linked list.
 * @line_no: current working line no. of Monty bytecodes file.
 */
void monty_nop(stack_t **stack_ptr, unsigned int line_no)
{
	(void)stack_ptr;
	(void)line_no;
}

/**
 * monty_pchar - Prints character in the top value
 *               node of stack_t linked list.
 * @stack_ptr: pointer to top node of stack_t linked list.
 * @line_no: current working line no. of Monty bytecodes file.
 */
void monty_pchar(stack_t **stack_ptr, unsigned int line_no)
{
	if ((*stack_ptr)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_no, "stack_ptr empty"));
		return;
	}

	if ((*stack_ptr)->next->n < 0 || (*stack_ptr)->next->n > 127)
	{
		set_op_tok_error(pchar_error(line_no,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack_ptr)->next->n);
}

/**
 * monty_pstr - Prints string contained in stack_t linked list.
 * @stack_ptr: pointer to top node of stack_t linked list.
 * @line_no: current working line no. of Monty bytecodes file.
 */
void monty_pstr(stack_t **stack_ptr, unsigned int line_no)
{
	stack_t *tmp = (*stack_ptr)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
	(void)line_no;
}
