/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:50:32 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/09 00:04:10 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last_occ;

	i = 0;
	last_occ = NULL;
	while (s[i])
	{
		if (s[i] == (const char)c)
			last_occ = (char *)&s[i];
		i++;
	}
	if ((const char)c == '\0')
		last_occ = (char *)&s[i];
	return (last_occ);
}
