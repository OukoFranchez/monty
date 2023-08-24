#include "monty.h"

void monty_add(stack_t **stack_ptr, unsigned int line_no);
void monty_sub(stack_t **stack_ptr, unsigned int line_no);
void monty_div(stack_t **stack_ptr, unsigned int line_no);
void monty_mul(stack_t **stack_ptr, unsigned int line_no);
void monty_mod(stack_t **stack_ptr, unsigned int line_no);

/**
 * monty_add - Adds two top values of stack_t linked list.
 * @stack_ptr: pointer to top node of stack_t linked list.
 * @line_no: current working line no. of Monty bytecodes file.
 *
 * Description: result is stored in the second value node
 *              from the top and top value removed.
 */
void monty_add(stack_t **stack_ptr, unsigned int line_no)
{
	if ((*stack_ptr)->next == NULL || (*stack_ptr)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_no, "add"));
		return;
	}

	(*stack_ptr)->next->next->n += (*stack_ptr)->next->n;

	monty_pop(stack_ptr, line_no);
}

/**
 * monty_sub - Subtracts second value from the top of
 *             stack_t linked list by top value.
 * @stack_ptr: pointer to top node of stack_t linked list.
 * @line_no: current working line no. of Monty bytecodes file.
 *
 * Description: result is stored in the second value node
 *              from the top and top value removed.
 */
void monty_sub(stack_t **stack_ptr, unsigned int line_no)
{
	if ((*stack_ptr)->next == NULL || (*stack_ptr)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_no, "sub"));
		return;
	}

	(*stack_ptr)->next->next->n -= (*stack_ptr)->next->n;

	monty_pop(stack_ptr, line_no);
}

/**
 * monty_div - Divides second value from top of
 *             stack_t linked list by top value.
 * @stack_ptr: pointer to top node of stack_t linked list.
 * @line_no: current working line no. of Monty bytecodes file.
 *
 * Description: result is stored in the second value node
 *              from the top and top value removed.
 */
void monty_div(stack_t **stack_ptr, unsigned int line_no)
{
	if ((*stack_ptr)->next == NULL || (*stack_ptr)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_no, "div"));
		return;
	}

	if ((*stack_ptr)->next->n == 0)
	{
		set_op_tok_error(div_error(line_no));
		return;
	}

	(*stack_ptr)->next->next->n /= (*stack_ptr)->next->n;

	monty_pop(stack_ptr, line_no);
}

/**
 * monty_mul - Multiplies second value from the top of
 *             stack_t linked list by the top value.
 * @stack_ptr: pointer to top node of stack_t linked list.
 * @line_no: current working line no. of Monty bytecodes file.
 *
 * Description: result is stored in the second value node
 *              from the top and top value removed.
 */
void monty_mul(stack_t **stack_ptr, unsigned int line_no)
{
	if ((*stack_ptr)->next == NULL || (*stack_ptr)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_no, "mul"));
		return;
	}

	(*stack_ptr)->next->next->n *= (*stack_ptr)->next->n;

	monty_pop(stack_ptr, line_no);
}

/**
 * monty_mod - Calculates modulus of the second value from the
 *             top of stack_t linked list  by top value.
 * @stack_ptr: pointer to top node of stack_t linked list.
 * @line_no: current working line no. of Monty bytecodes file.
 *
 * Description: result is stored in the second value node
 *              from the top and top value removed.
 */
void monty_mod(stack_t **stack_ptr, unsigned int line_no)
{
	if ((*stack_ptr)->next == NULL || (*stack_ptr)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_no, "mod"));
		return;
	}

	if ((*stack_ptr)->next->n == 0)
	{
		set_op_tok_error(div_error(line_no));
		return;
	}

	(*stack_ptr)->next->next->n %= (*stack_ptr)->next->n;

	monty_pop(stack_ptr, line_no);
}
