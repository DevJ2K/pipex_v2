/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:26:20 by tajavon           #+#    #+#             */
/*   Updated: 2024/06/16 01:02:42 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "pipex.h"

static void	write_in_pipe(char *cmd, int pipe_fd[2], char **envp)
{
	close(pipe_fd[0]);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	execute_cmd(cmd, envp);
}

static void	read_pipe_to_file(
	int argc, char **argv, int pipe_fd[2], char **envp)
{
	int	out_fd;

	if (!ft_strcmp(argv[1], "here_doc"))
		out_fd = ft_open(argv[argc - 1], 'a');
	else
		out_fd = ft_open(argv[argc - 1], 'w');
	close(pipe_fd[1]);
	dup2(out_fd, STDOUT_FILENO);
	close(out_fd);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	execute_cmd(argv[argc - 2], envp);
}

static t_pid_list	*create_processes(
	int argc, char **argv, char **envp, int fd[2])
{
	t_pid_list	*pid_list;
	pid_t		current_pid;
	int			i;

	pid_list = NULL;
	i = 2 + !ft_strcmp(argv[1], "here_doc");
	while (i < argc - 1)
	{
		current_pid = fork();
		if (current_pid == -1)
			ft_error("Failed to clone the calling process.", -1);
		ft_lstadd_pid(&pid_list, ft_lstnew_pid(current_pid));
		if (current_pid == 0)
		{
			if (i + 1 == argc - 1)
				read_pipe_to_file(argc, argv, fd, envp);
			else
				write_in_pipe(argv[i], fd, envp);
		}
		i++;
	}
	return (pid_list);
}

static void	ft_pipex(int argc, char **argv, char **envp)
{
	t_pid_list	*pid_list;
	int			fd[2];

	if (pipe(fd) == -1)
		ft_error("Failed to create a one way communication channel.", -1);
	pid_list = create_processes(argc, argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	while (pid_list)
	{
		waitpid(pid_list->pid, NULL, 0);
		pid_list = pid_list->next;
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	in_fd;
	int	i;

	if (argc == 1)
		ft_error("./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2", 1);
	if (argc < 5)
		ft_error("Bad number of arguments.", 1);
	i = 2;
	if (!ft_strcmp(argv[1], "here_doc"))
		in_fd = handle_heredoc(argv[i++]);
	else
		in_fd = ft_open(argv[1], 'r');
	dup2(in_fd, STDIN_FILENO);
	close(in_fd);
	ft_pipex(argc, argv, envp);
	return (0);
}
