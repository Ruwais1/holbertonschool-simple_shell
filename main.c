#include "shell.h"

extern char **environ;

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
	pid_t pid;
	int status = 0;

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

		if (args != NULL && args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				free(args);
				free(line);
				exit(WEXITSTATUS(status));
			}

			pid = fork();

			if (pid == -1)
			{
				perror("fork");
				free(args);
				continue;
			}

			if (pid == 0)
			{
				execve(args[0], args, environ);
				perror(args[0]);
				exit(2);
			}
			else
			{
				wait(&status);
			}

			free(args);
		}
	}

	free(line);
	return (0);
}
