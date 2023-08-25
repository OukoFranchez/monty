#include "monty.h"

void add_monty(stack_t **stack_ptr, unsigned int line_no);
void sub_monty(stack_t **stack_ptr, unsigned int line_no);
void div_monty(stack_t **stack_ptr, unsigned int line_no);
void mul_monty(stack_t **stack_ptr, unsigned int line_no);
void mod_monty(stack_t **stack_ptr, unsigned int line_no);

/**
 * add_monty - Adds two top values of stack_t linked list.
 * @stack_ptr: pointer to top node of stack_t linked list.
 * @line_no: current working line no. of Monty bytecodes file.
 *
 * Description: result is stored in the second value node
 *              from the top and top value removed.
 */
void add_monty(stack_t **stack_ptr, unsigned int line_no)
{
	if ((*stack_ptr)->next == NULL || (*stack_ptr)->next->next == NULL)
	{
		set_op_token_error(short_stack_error(line_no, "add"));
		return;
	}

	(*stack_ptr)->next->next->n += (*stack_ptr)->next->n;

	pop_monty(stack_ptr, line_no);
}

/**
 * sub_monty - Subtracts second value from the top of
 *             stack_t linked list by top value.
 * @stack_ptr: pointer to top node of stack_t linked list.
 * @line_no: current working line no. of Monty bytecodes file.
 *
 * Description: result is stored in the second value node
 *              from the top and top value removed.
 */
void sub_monty(stack_t **stack_ptr, unsigned int line_no)
{
	if ((*stack_ptr)->next == NULL || (*stack_ptr)->next->next == NULL)
	{
		set_op_token_error(short_stack_error(line_no, "sub"));
		return;
	}

	(*stack_ptr)->next->next->n -= (*stack_ptr)->next->n;

	pop_monty(stack_ptr, line_no);
}

/**
 * div_monty - Divides second value from top of
 *             stack_t linked list by top value.
 * @stack_ptr: pointer to top node of stack_t linked list.
 * @line_no: current working line no. of Monty bytecodes file.
 *
 * Description: result is stored in the second value node
 *              from the top and top value removed.
 */
void div_monty(stack_t **stack_ptr, unsigned int line_no)
{
	if ((*stack_ptr)->next == NULL || (*stack_ptr)->next->next == NULL)
	{
		set_op_token_error(short_stack_error(line_no, "div"));
		return;
	}

	if ((*stack_ptr)->next->n == 0)
	{
		set_op_token_error(divError(line_no));
		return;
	}

	(*stack_ptr)->next->next->n /= (*stack_ptr)->next->n;

	pop_monty(stack_ptr, line_no);
}

/**
 * mul_monty - Multiplies second value from the top of
 *             stack_t linked list by the top value.
 * @stack_ptr: pointer to top node of stack_t linked list.
 * @line_no: current working line no. of Monty bytecodes file.
 *
 * Description: result is stored in the second value node
 *              from the top and top value removed.
 */
void mul_monty(stack_t **stack_ptr, unsigned int line_no)
{
	if ((*stack_ptr)->next == NULL || (*stack_ptr)->next->next == NULL)
	{
		set_op_token_error(short_stack_error(line_no, "mul"));
		return;
	}

	(*stack_ptr)->next->next->n *= (*stack_ptr)->next->n;

	pop_monty(stack_ptr, line_no);
}

/**
 * mod_monty - Calculates modulus of the second value from the
 *             top of stack_t linked list  by top value.
 * @stack_ptr: pointer to top node of stack_t linked list.
 * @line_no: current working line no. of Monty bytecodes file.
 *
 * Description: result is stored in the second value node
 *              from the top and top value removed.
 */
void mod_monty(stack_t **stack_ptr, unsigned int line_no)
{
	if ((*stack_ptr)->next == NULL || (*stack_ptr)->next->next == NULL)
	{
		set_op_token_error(short_stack_error(line_no, "mod"));
		return;
	}

	if ((*stack_ptr)->next->n == 0)
	{
		set_op_token_error(divError(line_no));
		return;
	}

	(*stack_ptr)->next->next->n %= (*stack_ptr)->next->n;

	pop_monty(stack_ptr, line_no);
}
