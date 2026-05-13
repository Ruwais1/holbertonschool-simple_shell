#include "shell.h"

/**
 * get_path_env - Finds the PATH variable in the environment
 *
 * Return: Pointer to the value of PATH, or NULL if not found
 */
char *get_path_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			return (environ[i] + 5);
		i++;
	}
	return (NULL);
}

/**
 * get_command_path - Resolves the full path of a command
 * @command: The command to resolve (e.g., "ls")
 *
 * Return: Full path to the command, or NULL if not found
 */
char *get_command_path(char *command)
{
	char *path_env, *path_copy, *dir, *full_path;

	if (strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
		{
			full_path = malloc(strlen(command) + 1);
			if (full_path)
				strcpy(full_path, command);
			return (full_path);
		}
		return (NULL);
	}
	path_env = get_path_env();
	if (!path_env)
		return (NULL);
	path_copy = malloc(strlen(path_env) + 1);
	if (!path_copy)
		return (NULL);
	strcpy(path_copy, path_env);
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (full_path)
		{
			strcpy(full_path, dir);
			strcat(full_path, "/");
			strcat(full_path, command);
			if (access(full_path, X_OK) == 0)
			{
				free(path_copy);
				return (full_path);
			}
			free(full_path);
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
