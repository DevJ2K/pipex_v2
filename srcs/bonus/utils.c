/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:17:55 by tajavon           #+#    #+#             */
/*   Updated: 2024/06/21 08:57:28 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "pipex.h"

static void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return ;
}

static char	*find_path(char **paths, char *cmd)
{
	char	*path_slash;
	char	*path_cmd;
	int		i;

	i = 0;
	while (paths[i])
	{
		if (ft_strncmp(paths[i], cmd, ft_strlen(paths[i])) == 0)
		{
			if (access(cmd, F_OK | X_OK) == 0)
				return (cmd);
		}
		path_slash = ft_strjoin(paths[i], "/");
		path_cmd = ft_strjoin(path_slash, cmd);
		free(path_slash);
		if (access(path_cmd, F_OK | X_OK) == 0)
			return (path_cmd);
		free(path_cmd);
		i++;
	}
	return (NULL);
}

/// @brief Get the path of the command.
/// @param env All environment variables of the user computer.
/// @param cmd The command you want to execute.
/// @return paths of the cmd. (NULL if command is not found)
char	*get_path(char	**env, char *cmd)
{
	char	*path_cmd;
	char	**paths;

	if (!env || !*env)
		return (NULL);
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			break ;
		env++;
	}
	if (!env || !*env)
		return (NULL);
	*env += 5;
	paths = ft_split(*env, ':');
	if (!paths)
		return (NULL);
	path_cmd = find_path(paths, cmd);
	ft_free_tab(paths);
	return (path_cmd);
}

/// @brief The ft_open() functions use open(), but handle errors.
/// or returns the file descriptor.
/// @param path The path to the file you want to open.
/// @param methods The methods you want to use to open.
/// [r: read | w: write | a: append]
/// @return The file descriptor of the filepath.
int	ft_open(char *path, char methods)
{
	int	fd;

	fd = -1;
	if (methods == 'r')
		fd = open(path, O_RDONLY, 0777);
	else if (methods == 'w')
		fd = open(path, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	else if (methods == 'a')
		fd = open(path, O_APPEND | O_WRONLY | O_CREAT, 0777);
	else
		ft_error("Your method to open the file not exist.", 2);
	if (fd == -1)
		ft_error("Failed to open the file.", 1);
	return (fd);
}

/// @brief Execute the command using the environment variables PATH.
/// @param cmd The command you want to execute.
/// @param envp The environment variables of the computer.
void	execute_cmd(char *cmd, char **envp)
{
	char	**cmd_params;
	char	*cmd_path;

	cmd_path = NULL;
	cmd_params = ft_split(cmd, ' ');
	if (!cmd_params)
		ft_error("Failed to allocate memory.", 1);
	if (access(cmd, F_OK | X_OK) == 0)
		cmd_path = cmd;
	else
		cmd_path = get_path(envp, cmd_params[0]);
	if (!cmd_path)
	{
		ft_free_tab(cmd_params);
		ft_error("Command not found or bad access.", 127);
	}
	if (execve(cmd_path, cmd_params, envp) == -1)
	{
		free(cmd_path);
		ft_free_tab(cmd_params);
		ft_error("Failed to execute the command.", 1);
	}
	free(cmd_path);
	ft_free_tab(cmd_params);
}
