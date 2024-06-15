/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:02:27 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/01 12:25:26 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_start_to_end(const char *s1, int start, int end)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = malloc((end - start + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	while (start + i < end)
	{
		s2[i] = s1[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	count_split(char const *str, char c)
{
	int		i;
	int		count;
	int		is_word;

	i = 0;
	count = 0;
	is_word = 0;
	while (str[i])
	{
		if (str[i] == (const char)c)
		{
			if (is_word == 1)
			{
				count++;
				is_word = 0;
			}
		}
		else
			is_word = 1;
		i++;
	}
	if (is_word)
		count++;
	return (count);
}

static char	**ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	main_loop(int i, char const *s, char c, char **tab)
{
	int	start;
	int	j;

	j = 0;
	start = -1;
	while (i++, s[i])
	{
		if (s[i] != (const char)c && start == -1)
			start = i;
		else if ((s[i] == (const char)c && start != -1))
		{
			tab[j++] = ft_strdup_start_to_end(s, start, i);
			if (!tab[j - 1])
				return (-1);
			start = -1;
		}
	}
	if (start != -1)
	{
		tab[j++] = ft_strdup_start_to_end(s, start, i);
		if (!tab[j - 1])
			return (-1);
	}
	tab[j] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	tab = malloc((count_split(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (main_loop(-1, s, c, tab) == -1)
		return (ft_free_tab(tab));
	return (tab);
}

// #include <stdio.h>
// int main(int ac, char **av)
// {
// 	char **tab;
// 	int	i;
// 	(void)ac;
// 	tab = ft_split(av[1], ' ');
// 	i = 0;
// 	while (tab[i])
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	}
// }
