#include "shell.h"

/**
 * execute_command - Executes a command using fork and execve
 * @args: Array of arguments (parsed user input)
 *
 * Return: Exit status of the executed command
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;
	char *cmd_path;

	if (args[0] == NULL)
		return (1);
	cmd_path = get_command_path(args[0]);
	if (cmd_path == NULL)
	{
		perror(args[0]);
		return (127);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		free(cmd_path);
		return (1);
	}
	if (pid == 0)
	{
		if (execve(cmd_path, args, environ) == -1)
		{
			perror(args[0]);
			free(cmd_path);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		free(cmd_path);
	}
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
