/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:43:25 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/11 11:20:30 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*start;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		start = *lst;
		while (start->next)
			start = start->next;
		start->next = new;
	}
}
