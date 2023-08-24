#include "monty.h"

/**
 * popError - Prints pop error messages for empty stacks
 * @line_number: Line number in script where error is present
 *
 * Return: (EXIT_FAILURE)
 */

int popError(unsigned int line_number)
{
	fprintf(stderr, "L%u: Impossible to pop empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pintError - Prints pint error message for empty stacks
 * @line_number: Line number in bytecode where error occured
 *
 * Return: (EXIT_FAILURE)
 */

int pintError(unsigned int line_number)
{
	fprintf(stderr, "L%d: cant pint, stack is empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - Prints monty math func errors for stacks
 *                     or queues smaller than 2 nodes
 *@line_number: Line number in bytecode where error occured
 *@op: Operation where error came from
 *
 * Return: (EXIT_FAILURE)
 */

int short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: cant %s, stack is too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * divError - prints division error messages for divisions of 0
 * @line_number: Line in bytecode where error occured
 *
 * Return: (EXIT_FAILURE)
 */

int divError(unsigned int line_number)
{
	fprintf(stderr, "L%u: Division by 0\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pcharError - prints pchar error msgs for empty stacks and non-char
 * 				values
 *@line_number: Line in bytecode where error occured
 *@message: Corresponding message to be printed
 *
 * Return: (EXIT_FAILURE)
 */

int pcharError(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
