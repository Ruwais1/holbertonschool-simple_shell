#include "shell.h"

/**
 * main - Entry point for the simple shell
 *
 * Return: Exit status of last command
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_bytes;
	char **args;
	int status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		read_bytes = getline(&line, &len, stdin);
		if (read_bytes == -1)
			break;
		args = split_line(line);
		if (args != NULL && args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				free(args);
				handle_exit(line);
			}
			status = execute_command(args);
			free(args);
		}
		else if (args != NULL)
			free(args);
	}
	free(line);
	return (status);
}
