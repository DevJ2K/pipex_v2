/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:57:55 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/07 00:09:14 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_toupper(int c)
{
	if (97 <= c && c <= 122)
		return (c - 32);
	return (c);
}

// int	main(void)
// {
// 	printf("%c", toupper('c'));
// 	printf("%c", toupper('D'));
// 	printf("%c", toupper('z'));
// 	printf("%c", toupper('a'));
// 	printf("%c", toupper('4'));
// }
