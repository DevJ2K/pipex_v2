/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 01:02:44 by tajavon           #+#    #+#             */
/*   Updated: 2024/06/16 01:02:50 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "pipex.h"

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

int	handle_heredoc(char *limiter)
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
