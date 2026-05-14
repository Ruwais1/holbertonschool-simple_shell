#include "shell.h"

/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL, **args;
	size_t len = 0;
	ssize_t read_bytes;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		read_bytes = getline(&line, &len, stdin);
		if (read_bytes == -1)
			break;
		args = split_line(line);
		if (args && args[0])
		{
			if (strcmp(args[0], "exit") == 0)
			{
				free(args);
				handle_exit(line);
			}
			if (strcmp(args[0], "env") == 0)
				print_env();
			else
				execute_command(args);
			free(args);
		}
		else if (args)
			free(args);
	}
	free(line);
	return (0);
}
