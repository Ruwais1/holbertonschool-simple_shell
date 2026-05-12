#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* --- Prototypes --- */

char **split_line(char *line);
void handle_exit(char *line);
#endif /* SHELL_H */
