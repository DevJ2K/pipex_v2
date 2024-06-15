/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:43:35 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/01 12:16:21 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int	found_newlines(char *all_read)
{
	int	i;

	i = 0;
	if (!all_read)
		return (0);
	while (all_read[i])
	{
		if (all_read[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
