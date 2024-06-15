/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:13:48 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/01 12:23:35 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char *src, size_t nb)
{
	size_t	end_dest;
	size_t	i;

	i = 0;
	end_dest = ft_strlen(dest);
	while (i < nb && src[i] != '\0')
	{
		dest[end_dest + i] = src[i];
		i++;
	}
	dest[end_dest + i] = '\0';
	return (dest);
}
