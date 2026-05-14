#include "shell.h"

/**
 * handle_exit - exits the shell
 * @line: user input
 * @status: exit status
 */
void handle_exit(char *line, int status)
{
	free(line);
	exit(status);
}
