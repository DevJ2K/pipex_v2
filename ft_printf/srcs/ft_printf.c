/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:26:48 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/16 20:15:40 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		print_length;
	va_list	args;

	if (!str)
		return (0);
	i = -1;
	print_length = 0;
	va_start(args, str);
	while (i++, str[i])
	{
		if (is_printf_formatter(str[i], str[i + 1]))
		{
			print_length += print_in_format(str[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			print_length++;
		}
	}
	va_end(args);
	return (print_length);
}

int	print_in_format(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_putptr(va_arg(args, size_t)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putunsigned(va_arg(args, int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthexa(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	is_printf_formatter(char c1, char c2)
{
	if (c1 != '%')
		return (0);
	if (c2 == 'c')
		return (1);
	else if (c2 == 's')
		return (1);
	else if (c2 == 'p')
		return (1);
	else if (c2 == 'd')
		return (1);
	else if (c2 == 'i')
		return (1);
	else if (c2 == 'u')
		return (1);
	else if (c2 == 'x')
		return (1);
	else if (c2 == 'X')
		return (1);
	else if (c2 == '%')
		return (1);
	else
		return (0);
}
