/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:26:20 by tajavon           #+#    #+#             */
/*   Updated: 2024/06/15 21:30:12 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "pipex.h"

static int	execute_process_1(char *file, char *cmd, int pipe_fd[2], char **envp)
{
	int	fd;

	fd = ft_open(file, 'r');
	close(pipe_fd[0]);
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	execute_cmd(cmd, envp);
}

static int	execute_process_2(char *file, char *cmd, int pipe_fd[2], char **envp)
{
	int	fd;

	fd = ft_open(file, 'w');
	close(pipe_fd[1]);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	execute_cmd(cmd, envp);
}

/// @brief Create a pipe to execute command.
/// @param cmd The command you want to run in the pipe
/// @param envp The environment variables
/// @return Returns -1 for errors, 0 for successful
static int	ft_pipe(char **argv, char **envp)
{
	pid_t	cmd_pid_1;
	pid_t	cmd_pid_2;
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

	waitpid(cmd_pid_1, NULL, 0);
	waitpid(cmd_pid_2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd_out;
	int	fd_in;

	if (argc == 1)
		ft_error("./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2", 1);
	if (argc != 5)
		ft_error("Bad number of arguments.", 1);
	close(ft_open(argv[4], 'w'));
	ft_pipe(argv, envp);



	return (0);
}
