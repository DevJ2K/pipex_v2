/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:26:20 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/04 08:55:23 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "pipex.h"

/// @brief Create a pipe to execute command.
/// @param cmd The command you want to run in the pipe
/// @param envp The environment variables
/// @return Returns -1 for errors, 0 for successful
static int	ft_pipe(char *cmd, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_error("Failed to create a one way communication channel.", -1);
	pid = fork();
	if (pid == -1)
		ft_error("Failed to clone the calling process.", -1);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		execute_cmd(cmd, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
	return (0);
}

static void	write_in_heredoc(char *limiter)
{
	char	*input;

	while (1)
	{
		input = ft_strdup(get_next_line(0));
		if (!input)
			ft_error("Failed to allocate memory.", 1);
		if (!ft_strncmp(input, limiter, ft_strlen(limiter)))
		{
			free(input);
			break ;
		}
		ft_printf("%s", input);
		free(input);
	}
}

static int	handle_heredoc(char *limiter)
{
	int	in_fd;

	unlink(".tmp_here_doc");
	in_fd = ft_open(".tmp_here_doc", 'a');
	dup2(in_fd, 1);
	close(in_fd);
	write_in_heredoc(limiter);
	in_fd = ft_open(".tmp_here_doc", 'r');
	unlink(".tmp_here_doc");
	return (in_fd);
}

int	main(int argc, char **argv, char **envp)
{
	int		in_fd;
	int		out_fd;
	int		i;

	if (argc == 1)
		ft_error("./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2", 1);
	if (argc < 5)
		ft_error("Bad number of arguments.", 1);
	i = 2;
	if (!ft_strcmp(argv[1], "here_doc"))
		in_fd = handle_heredoc(argv[i++]);
	else
		in_fd = ft_open(argv[1], 'r');
	dup2(in_fd, 0);
	close(in_fd);
	while (i < argc - 2)
		ft_pipe(argv[i++], envp);
	if (!ft_strcmp(argv[1], "here_doc"))
		out_fd = ft_open(argv[argc - 1], 'a');
	else
		out_fd = ft_open(argv[argc - 1], 'w');
	dup2(out_fd, 1);
	close(out_fd);
	execute_cmd(argv[argc - 2], envp);
	return (0);
}
