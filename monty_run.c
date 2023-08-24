#include "monty.h"
#include <string.h>
#define _POSIX_C_SOURCE 200809L

void free_tokens(void);
unsigned int token_arr_len(void);
int is_empty_line(char *line, char *delim);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int monty_run(FILE *script_fd);

/**
 * free_tokens - Frees global op_toks array of strings.
 */
void free_tokens(void)
{
	size_t k = 0;

	if (op_toks == NULL)
	{
		return;
	}

	for (k = 0; op_toks[k]; k++)
		free(op_toks[k]);

	free(op_toks);
}

/**
 * token_arr_len - computes length of current op_toks.
 *
 * Return: Length of current op_toks as integers.
 */
unsigned int token_arr_len(void)
{
	unsigned int token_length = 0;

	while (op_toks[token_length])
	{
		token_length++;
	}
	return (token_length);
}

/**
 * is_empty_line - Checks if line read from getline only contains delimiters.
 * @line: pointer to the line.
 * @delim: string of delimiter characters.
 *
 * Return: If the line only contains delimiters only - 1. Otherwise - 0.
 */
int is_empty_line(char *line, char *delim)
{
	int k, j;

	for (k = 0; line[k]; k++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (line[k] == delim[j])
				break;
		}
		if (delim[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func - Matches an opcode with its respective function.
 * @opcode: opcode to match.
 *
 * Return: pointer to the respective function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", push_monty},
		{"pall", pall_monty},
		{"pint", pint_monty},
		{"pop", pop_monty},
		{"swap", swap_monty},
		{"add", add_monty},
		{"nop", monty_nop},
		{"sub", sub_monty},
		{"div", div_monty},
		{"mul", mul_monty},
		{"mod", mod_monty},
		{"pchar", pchar_monty},
		{"pstr", pstr_monty},
		{"rotl", rotl_monty},
		{"rotr", rotr_monty},
		{"stack", stack_monty},
		{"queue", queue_monty},
		{NULL, NULL}
	};
	int k;

	for (k = 0; op_funcs[k].opcode; k++)
	{
		if (strcmp(opcode, op_funcs[k].opcode) == 0)
			return (op_funcs[k].f);
	}

	return (NULL);
}

/**
 * monty_run - Primary function executing Monty bytecodes script.
 * @script_fd: File descriptor for open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, error code on failure.
 */
int monty_run(FILE *script_fd)
{
	stack_t *stack_ptr = NULL;
	char *line = NULL;
	size_t length = 0;
	size_t exit_status = EXIT_SUCCESS;
	unsigned int line_no = 0;
	unsigned int prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (initStack(&stack_ptr) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &length, script_fd) != -1)
	{
		line_no++;
		op_toks = strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			freeStack(&stack_ptr);
			return (mallocError());
		}

		/* comment line */
		else if (op_toks[0][0] == '#')
		{
			free_tokens();
			continue;
		}
		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL)
		{
			freeStack(&stack_ptr);
			exit_status = unknown_op_error(op_toks[0], line_no);
			free_tokens();
			break;
		}
		prev_tok_len = token_arr_len();
		op_func(&stack_ptr, line_no);
		if (token_arr_len() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_tokens();
			break;
		}
		free_tokens();
	}
	freeStack(&stack_ptr);

	if (line && *line == 0)
	{
		free(line);
		return (mallocError());
	}

	free(line);
	return (exit_status);
}
