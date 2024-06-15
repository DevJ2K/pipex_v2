/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:24:20 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/08 15:31:53 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	char		c;

	nb = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	c = nb % 10 + 48;
	write(fd, &c, 1);
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
