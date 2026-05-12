.TH SIMPLE_SHELL 1 "May 2026"

.SH NAME
simple_shell \- simple UNIX command line interpreter

.SH DESCRIPTION
Simple Shell is a simple UNIX command line interpreter written in C.

.PP
The shell can execute commands, handle arguments,
search commands using PATH, and support built-in commands.

.SH TASKS

.TP
.B \[bu] Task 0
Create AUTHORS and README files.

.TP
.B \[bu] Task 1
Create a simple shell.

.TP
.B \[bu] Task 2
Handle commands with arguments.

.TP
.B \[bu] Task 3
Handle the PATH variable.

.TP
.B \[bu] Task 4
Implement the built-in
.B exit
command.

.TP
.B \[bu] Task 5
Implement the built-in
.B env
command.

.SH COMPILATION
.B gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

.SH USAGE
.B ./hsh

.SH AUTHORS
Fahad Almidaj
.br
Jana Alhazmi
