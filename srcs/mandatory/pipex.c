/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:26:20 by tajavon           #+#    #+#             */
/*   Updated: 2024/06/17 09:03:14 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "pipex.h"

/// @brief Execute the command from the file to the pipe.
/// @param file The file to use as input for the command.
/// @param cmd The command to execute.
/// @param pipe_fd The fd array you have pipe().
/// @param envp The environment variables.
static void	execute_process_1(
	char *file, char *cmd, int pipe_fd[2], char **envp)
{
	int	fd;

	close(pipe_fd[0]);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	fd = ft_open(file, 'r');
	dup2(fd, STDIN_FILENO);
	close(fd);
	execute_cmd(cmd, envp);
}

/// @brief Execute the command from the pipe to the file.
/// @param file The file to use as output for the command.
/// @param cmd The command to execute.
/// @param pipe_fd The fd array you have pipe().
/// @param envp The environment variables.
static void	execute_process_2(
	char *file, char *cmd, int pipe_fd[2], char **envp)
{
	int	fd;

	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	fd = ft_open(file, 'w');
	dup2(fd, STDOUT_FILENO);
	close(fd);
	execute_cmd(cmd, envp);
}

/// @brief This function is used to reproduce the
/// behavior of a pipe between two commands.
/// @param argv Arguments containing file names and commands.
/// @param envp The environment variables.
static void	ft_pipe(char **argv, char **envp)
{
	pid_t	cmd_pid_1;
	pid_t	cmd_pid_2;
	int		status_cmd_1;
	int		status_cmd_2;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_error("Failed to create a one way communication channel.", -1);
	cmd_pid_1 = fork();
	if (cmd_pid_1 == -1)
		ft_error("Failed to clone the calling process.", -1);
	if (cmd_pid_1 == 0)
		execute_process_1(argv[1], argv[2], fd, envp);
	cmd_pid_2 = fork();
	if (cmd_pid_2 == -1)
		ft_error("Failed to clone the calling process.", -1);
	if (cmd_pid_2 == 0)
		execute_process_2(argv[4], argv[3], fd, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(cmd_pid_1, &status_cmd_1, 0);
	waitpid(cmd_pid_2, &status_cmd_2, 0);
	if (WIFEXITED(status_cmd_2))
		exit(WEXITSTATUS(status_cmd_2));
}

int	main(int argc, char **argv, char **envp)
{
	if (argc == 1)
		ft_error("./pipex file1 cmd1 cmd2 file2", 1);
	if (argc != 5)
		ft_error("Bad number of arguments.", 1);
	close(ft_open(argv[4], 'w'));
	ft_pipe(argv, envp);
}
