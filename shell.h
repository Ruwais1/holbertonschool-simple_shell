#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

/* --- Variables --- */
extern char **environ;

/* --- Prototypes --- */
char **split_line(char *line);
int execute_command(char **args);
void handle_exit(char *line);

#endif /* SHELL_H */
