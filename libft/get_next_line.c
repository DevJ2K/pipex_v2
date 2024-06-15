/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:43:42 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/01 12:24:47 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static void	new_all_read(char **all_read, char *buffer, int nb_bytes_read)
{
	char	*temp;
	int		all_read_length;

	all_read_length = 0;
	if (*all_read)
		all_read_length = ft_strlen(*all_read);
	temp = malloc((all_read_length + nb_bytes_read + 1) * sizeof(char));
	if (!temp)
		return ;
	if (*all_read)
		ft_strcpy(temp, *all_read);
	ft_strncat(temp, buffer, nb_bytes_read);
	free(*all_read);
	*all_read = temp;
}

static void	read_and_add(int fd, char **all_read)
{
	char		*buffer;
	int			nb_bytes_read;

	nb_bytes_read = 1;
	while (!found_newlines(*all_read) && nb_bytes_read > 0)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return ;
		nb_bytes_read = (int)read(fd, buffer, BUFFER_SIZE);
		if ((!(*all_read) && nb_bytes_read == 0) || nb_bytes_read == -1)
		{
			free(buffer);
			return ;
		}
		buffer[nb_bytes_read] = '\0';
		if (!(*all_read))
			(*all_read) = ft_strdup("");
		if (!(*all_read))
			return ;
		new_all_read(all_read, buffer, nb_bytes_read);
		free(buffer);
	}
}

static char	*extract_line(char *all_read)
{
	int		i;
	int		line_length;
	char	*line;

	i = 0;
	line_length = 0;
	while (all_read[line_length] && all_read[line_length] != '\n')
	{
		line_length++;
	}
	if (all_read[line_length] == '\n')
		line_length++;
	line = malloc((line_length + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (i < line_length)
	{
		line[i] = all_read[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static void	clean_read_line(char **all_read)
{
	int		i;
	int		j;
	char	*temp;

	j = 0;
	while ((*all_read)[j] && (*all_read)[j] != '\n')
		j++;
	if ((*all_read)[j] == '\n')
		j++;
	temp = malloc((ft_strlen(*all_read) - j + 1) * sizeof(char));
	if (!temp)
		return ;
	i = 0;
	while ((*all_read)[j])
		temp[i++] = (*all_read)[j++];
	temp[i] = '\0';
	free(*all_read);
	*all_read = temp;
}

char	*get_next_line(int fd)
{
	static char	*all_read[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	read_and_add(fd, &all_read[fd]);
	if (!all_read[fd])
		return (NULL);
	line = extract_line(all_read[fd]);
	clean_read_line(&all_read[fd]);
	if (all_read[fd] && *all_read[fd] == '\0')
	{
		free(all_read[fd]);
		all_read[fd] = NULL;
	}
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>
// int	main(void)
// {
// 	int		fd;
// 	int		i;
// 	char	*line;

// 	fd = open("bible.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	i = 1;
// 	while (i)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// 	return (0);
// }
