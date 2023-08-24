#include "monty.h"

/**
 * usageError - Prints Error based on usage
 *
 * Return: (EXIT_FAILURE) always
 */

int usageError(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * mallocError - Prints error message where malloc is concerned
 *
 * Return: (EXIT_FAILURE)
 */

int mallocError(void)
{
	fprintf(stderr, "Error: Malloc Failure\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - Prints error during file opening w/ file name
 *@filename: Name of the file that didn't open
 *
 *Return: (EXIT_FAILURE)
 */

int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Cant Open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - Prints unknown operation error message
 * @opcode: Opcode where error happened
 * @line_number: Line number in bytecode where error occured
 *
 * Return: (EXIT_FAILURE)
 */

int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: Unknown Operation %s\n", line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error	- Print invalid monty_push arg error message
 * @line_number: Line number in bytecode where error happened
 *
 *Return: (EXIT_FAILURE)
 */

int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
