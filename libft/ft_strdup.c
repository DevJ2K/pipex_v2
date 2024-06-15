/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:28:54 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/11 11:01:15 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	str = (char *)malloc((ft_strlen(ptr) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (ptr[i])
	{
		str[i] = ptr[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
