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
char *get_path_env(void);
char *get_command_path(char *command);
void print_env(void);
#endif /* SHELL_H */
