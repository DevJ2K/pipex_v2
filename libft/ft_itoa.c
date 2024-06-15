/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:09:25 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/08 12:43:51 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

long int	n_len(long int nb)
{
	long int	len;
	long int	power;

	power = 10;
	len = 1;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb / power > 0)
	{
		len++;
		power *= 10;
	}
	return (len);
}

long int	ft_power(long int p)
{
	long int	pow;

	pow = 1;
	while (p > 0)
	{
		pow *= 10;
		p--;
	}
	return (pow);
}

char	*ft_itoa(int n)
{
	long int	len;
	long int	nb;
	long int	i;
	char		*str;

	nb = n;
	i = 0;
	len = n_len(nb);
	str = malloc((len + 1) * (sizeof(char)));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[i] = '-';
		nb *= -1;
		i++;
	}
	while (i < len)
	{
		str[i] = (nb / ft_power(len - i - 1)) + 48;
		nb = nb % ft_power(len - i - 1);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(-2147483648));
// 	printf("%s\n", ft_itoa(2147483647));
// 	printf("%s\n", ft_itoa(-0));
// 	printf("%s\n", ft_itoa(-6));
// 	printf("%s\n", ft_itoa(-14));
// 	printf("%s\n", ft_itoa(26));
// 	printf("%s\n", ft_itoa(2));
// 	printf("%s\n", ft_itoa(100));
// 	printf("%s\n", ft_itoa(10010));
// 	printf("%s", ft_itoa(-2147483648));
// }
