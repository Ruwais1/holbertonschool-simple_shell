#include "shell.h"
/**
 * main - Entry point for the simple shell
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_bytes;
	char **args;
	while (1)
	{ if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "($) ", 4);
	 read_bytes = getline(&line, &len, stdin);
		if (read_bytes == -1)
		{
			break;
		}
		args = split_line(line);
		if (args != NULL && args[0] != NULL)
		{ if (strcmp(args[0], "exit") == 0)
			{  
				free(args);
			}   handle_exit(line);
		  if (strcmp(args[0], "env") == 0)
			{ 
				print_env();
				free(args);
				continue;
			}
			  
			execute_command(args);
			free(args);
		} else if (args != NULL)
		{ free(args);
		}
return (0);
	}
}
