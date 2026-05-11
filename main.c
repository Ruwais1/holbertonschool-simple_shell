#include "shell.h"

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_bytes;

	while (1)
	{
		/* Print prompt only if interactive mode */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		/* Read user input */
		read_bytes = getline(&line, &len, stdin);

		/* Handle EOF (Ctrl+D) */
		if (read_bytes == -1)
		{
			free(line);
			break;
		}

		/* Print the input to test if it read correctly */
		write(STDOUT_FILENO, line, read_bytes);
	}

	return (0);
}
