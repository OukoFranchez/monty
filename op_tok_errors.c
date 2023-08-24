#include "monty.h"

/**
 * set_op_token_error - sets last element of op_toks to be an error code
 * @error_code: Integer to store as a string in op_toks
 */

void set_op_token_error(int error_code)
{
	int toks_len = 0, i = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = token_arr_len();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!op_toks)
	{
		mallocError();
		return;
	}
	while (i < toks_len)
	{
		new_toks[i] = op_toks[i];
		i++;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
		free(new_toks);
		mallocError();
		return;
	}
	new_toks[i++] = exit_str;
	new_toks[1] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
