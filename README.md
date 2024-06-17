Pipex
Description
The pipex project aims to provide an understanding of Unix processes and inter-process communication through pipes. The goal is to replicate the shell command piping functionality, allowing the output of one command to be used as the input for another. This project serves as an excellent exercise in system programming, focusing on process management, file operations, and error handling.

Objective
The main objective of this project is to create a program that behaves like the shell command below:

sh
Copier le code
< file1 cmd1 | cmd2 > file2
Your program should be executed as follows:

sh
Copier le code
./pipex file1 cmd1 cmd2 file2
Arguments
file1: The input file.
cmd1: The first shell command to execute.
cmd2: The second shell command to execute.
file2: The output file.
Example
Running the command:

sh
Copier le code
./pipex infile "ls -l" "wc -l" outfile
Should produce the same result as the shell command:

sh
Copier le code
< infile ls -l | wc -l > outfile
Requirements
Mandatory Part
Implement the program to handle exactly two commands with a single pipe.
Handle errors gracefully to ensure the program does not crash unexpectedly.
Ensure there are no memory leaks.
Bonus Part
Support multiple pipes with more than two commands:
sh
Copier le code
./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
This should mimic the shell command:

sh
Copier le code
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
Support the "here_doc" functionality:
sh
Copier le code
./pipex here_doc LIMITER cmd cmd1 file
This should mimic the shell command:

sh
Copier le code
cmd << LIMITER | cmd1 >> file
Allowed Functions
open, close, read, write
malloc, free, perror, strerror, access
dup, dup2, execve, exit, fork, pipe
unlink, wait, waitpid
Your own ft_printf or an equivalent
Libft is allowed
Project Structure
Makefile: Compilation rules.
Source files (*.c): Implementation of the pipex program.
Header files (*.h): Declarations for functions and macros.
Compilation
Use the provided Makefile to compile the project:

sh
Copier le code
make
This will create the pipex executable.

Usage
Run the program with the required arguments:

sh
Copier le code
./pipex file1 cmd1 cmd2 file2
Examples
sh
Copier le code
./pipex infile "grep a1" "wc -w" outfile
This should produce the same result as:

sh
Copier le code
< infile grep a1 | wc -w > outfile
Error Handling
Ensure to handle and report errors properly without causing segmentation faults, bus errors, or double frees.
Check for proper file permissions and existence.
Manage memory to avoid leaks.
Learning Outcomes
Through this project, you will gain a deeper understanding of:

Process creation and management using fork.
Inter-process communication using pipe.
Redirecting input and output with dup and dup2.
Executing commands with execve.
Handling file operations and errors in Unix.
Conclusion
The pipex project is a hands-on approach to learning the intricacies of process communication and management in Unix-like systems. It strengthens your understanding of system-level programming and equips you with skills essential for advanced programming tasks.
