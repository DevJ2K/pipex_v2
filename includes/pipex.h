/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:26:11 by tajavon           #+#    #+#             */
/*   Updated: 2024/06/15 23:28:27 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <sys/types.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_pid_list
{
	pid_t				pid;
	struct s_pid_list	*next;
}						t_pid_list;

char	*get_path(char	**env, char *cmd);
void	ft_error(char *str, int errnum);
int		ft_open(char *path, char methods);
void	execute_cmd(char *cmd, char **envp);

t_pid_list	*ft_lstnew_pid(pid_t pid);
void		ft_lstadd_pid(t_pid_list **lst, t_pid_list *new);

#endif
