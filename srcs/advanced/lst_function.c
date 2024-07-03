/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 23:21:56 by tajavon           #+#    #+#             */
/*   Updated: 2024/06/15 23:28:38 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_lstadd_pid(t_pid_list **lst, t_pid_list *new)
{
	t_pid_list	*start;

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

t_pid_list	*ft_lstnew_pid(pid_t pid)
{
	t_pid_list	*lnew;

	lnew = malloc(sizeof(t_pid_list));
	if (!lnew)
		return (NULL);
	lnew->pid = pid;
	lnew->next = NULL;
	return (lnew);
}
