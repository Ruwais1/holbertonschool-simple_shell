#include "shell.h"

extern char **environ;

/**
 * execute_command - Executes a command using fork and execve
 * @args: Array of arguments (parsed user input)
 *
 * Return: Always 1 (to continue the shell loop)
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
		return (1);

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (1);
	}
	if (pid == 0)
	{
		/* Execute the command with current environment variables */
		if (execve(args[0], args, environ) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}

	return (1);
}
