#include "shell.h"

/**
 * handle_exit - exits the shell
 * @line: input line
 */
void handle_exit(char *line, int status)
{
	free(line);
	exit(status);
}
