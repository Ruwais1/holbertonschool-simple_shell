#include "shell.h"

/**
 * split_line - Splits a string into an array of words (tokens)
 * @line: The string read from standard input
 *
 * Return: Array of pointers to the words
 */
char **split_line(char *line)
{
	int bufsize = 64;
	int i = 0;
	char **tokens;
	char *token;

	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
		return (NULL);

	token = strtok(line, " \n\t\r");
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, " \n\t\r");
	}
	tokens[i] = NULL;

	return (tokens);
}
