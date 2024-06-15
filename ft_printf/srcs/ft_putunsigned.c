/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:18:16 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/16 19:58:13 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	long unsigned int	nb;
	int					len;
	char				c;

	nb = n;
	len = 0;
	if (nb >= 10)
		len += ft_putunsigned(nb / 10);
	c = nb % 10 + 48;
	len += write(1, &c, 1);
	return (len);
}
