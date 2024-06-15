/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:26:11 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/03 01:32:28 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

char	*get_path(char	**env, char *cmd);
void	ft_error(char *str, int errnum);
int		ft_open(char *path, char methods);
void	execute_cmd(char *cmd, char **envp);

#endif
