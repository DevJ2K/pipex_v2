/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:04:29 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/07 00:09:08 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_tolower(int c)
{
	if (65 <= c && c <= 90)
		return (c + 32);
	return (c);
}

// int	main(void)
// {
// 	printf("%c", tolower('C'));
// 	printf("%c", tolower('e'));
// 	printf("%c", tolower('Z'));
// 	printf("%c", tolower('A'));
// 	printf("%c", tolower('-'));
// 	printf("%c", tolower('4'));
// }
