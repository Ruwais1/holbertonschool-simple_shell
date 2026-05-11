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
	char **args;
	int i;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		read_bytes = getline(&line, &len, stdin);
		if (read_bytes == -1)
		{
			free(line);
			break;
		}

		args = split_line(line);
		if (args != NULL)
		{
			for (i = 0; args[i] != NULL; i++)
			{
				printf("Word %d: %s\n", i, args[i]);
			}
			free(args);
		}
	}
	return (0);
}
