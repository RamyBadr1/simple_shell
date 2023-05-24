# BUILDING A SIMPLE SHELL FROM SCRATCH USING C

#This is an ALX collaboration project on Shell. this simple shell mimics the Bash shell.

## Project was completed using

    C language
    Shell
    Betty linter

## General Requirements

    All files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
    All files should end with a new line
    A README.md file, at the root of the folder of the project is mandatory
    Use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
    Shell should not have any memory leaks
    No more than 5 functions per file
    All header files should be include guarded
    Write a README with the description of the project

## Description

Simple shell  reads commands from either a file or standard input and executes them.
How simple shell works

    Prints a prompt and waits for a command
    Creates a child process in which the command is checked
    Checks for built-ins, aliases in the PATH, and local executable programs
    The child process is replaced by the command, which accepts arguments
    When the command is done, the program returns to the parent process and prints the prompt
    The program is ready to receive a new command
    To exit: press Ctrl-D or enter "exit" (with or without a status)
    Works also in non interactive mode

## Compilation

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Authors

alidrisy <125469989+alidrisy@users.noreply.github.com>
RamyBadr1 <ramybadr054@gmail.com>
