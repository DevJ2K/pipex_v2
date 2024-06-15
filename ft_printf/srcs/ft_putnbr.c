/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:24:20 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/16 19:58:05 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long int	nb;
	int			len;
	char		c;

	nb = n;
	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		len += ft_putnbr(nb / 10);
	c = nb % 10 + 48;
	len += write(1, &c, 1);
	return (len);
}

// int	main(void)
// {
// 	ft_putnbr_fd(0);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(10);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(-1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(3000);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(-2147483648);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(2147483647);
// 	write(1, "\n", 1);
// }
