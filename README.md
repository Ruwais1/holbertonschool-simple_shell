# Simple Shell

## Description

Simple Shell is a simple UNIX command line interpreter written in C as part of the Holberton School low-level programming curriculum.

This project recreates a basic version of the UNIX shell and demonstrates how command execution works internally in operating systems.

The shell reads commands entered by the user, processes them, and executes programs using system calls such as `fork` and `execve`.

The shell supports interactive mode, command execution, argument handling, PATH resolution, and basic built-in commands.

---

## Features

- Display a command prompt
- Execute commands entered by the user
- Handle command line arguments
- Search commands using the PATH environment variable
- Built-in `exit` command
- Built-in `env` command
- Error handling
- Handle End Of File (`Ctrl + D`)

---

## Tasks

- Task 0: Create AUTHORS and README files
- Task 1: Create a simple shell
- Task 2: Handle commands with arguments
- Task 3: Handle the PATH variable
- Task 4: Implement the built-in `exit` command
- Task 5: Implement the built-in `env` command

---

## Compilation

Compile the shell using:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

---

## Usage

Run the shell:

```bash
./hsh
```

Example:

```bash
$ ls
$ pwd
$ env
$ exit
```

---

## Flow of Execution

1. Display the shell prompt
2. Read user input
3. Parse the command line
4. Search the command in PATH
5. Create a child process using `fork`
6. Execute the command using `execve`
7. Wait for the process to finish

---

## Project Structure

```text
.
├── main.c
├── shell.h
├── parser.c
├── execute.c
├── path.c
├── builtin_exit.c
├── builtin_env.c
├── AUTHORS
└── README.md
```

---

## Manual Page

To access the manual page:

```bash
man ./man_1_simple_shell
```

Alternative command:

```bash
groff -man -Tascii man_1_simple_shell
```

---

## Requirements

- Ubuntu 20.04 LTS
- GCC compiler
- Betty coding style

---

## Authors

- Fahad Almidaj
- Jana Alhazmi
