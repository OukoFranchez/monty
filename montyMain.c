#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 * main - Entry point for monty interpreter
 *
 * @argc: Argument count passed to program
 * @argv: pointer to array of char pointers of argments
 *
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on failure
 */

int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (usageError());
		script_fd = fopen(argv[1], "r");
		if (script_fd == NULL)
			return (f_open_error(argv[1]));
		exit_code = monty_run(script_fd);
		fclose(script_fd);
		return (exit_code);
}