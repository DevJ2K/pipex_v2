/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:33:49 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/04 09:08:15 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

/// @brief Displays error and exits with the errnum you given.
/// @param str The error message you want to display.
/// @param errnum The error number of your error.
void	ft_error(char *str, int errnum)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	exit(errnum);
}
