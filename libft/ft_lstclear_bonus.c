/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:22:28 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/11 11:20:39 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*to_del;

	if (!lst || !*lst)
		return ;
	temp = *lst;
	while (temp)
	{
		to_del = temp;
		temp = temp->next;
		ft_lstdelone(to_del, del);
	}
	*lst = NULL;
}
