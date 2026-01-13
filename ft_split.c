/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:09:02 by jemonthi          #+#    #+#             */
/*   Updated: 2025/10/29 18:49:19 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	count_words(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
			{
				i++;
				if (s[i] == '\0')
					return (count);
			}
		}
		i++;
	}
	return (count);
}

static int	ft_size(const char *s, char c, int end)
{
	int	i;

	i = 0;
	while (s[end + i] && s[end + i] != c)
		i++;
	return (i);
}

static void	ft_free_tab_s(char **tab, int size)
{
	while (size > 0)
	{
		size--;
		free(tab[size]);
	}
	free(tab);
}

static char	**ft_splitter(char const *s, char c, char **tab_s, int end)
{
	int	i_tab;

	i_tab = 0;
	while (s && s[end])
	{
		while (s[end] && s[end] == c)
			end++;
		if (!s[end])
			break ;
		if (s[end] != c)
		{
			tab_s[i_tab] = ft_substr((char *)s, end, ft_size(s, c, end));
			if (!tab_s[i_tab])
			{
				ft_free_tab_s(tab_s, i_tab);
				return (NULL);
			}
			i_tab++;
		}
		end = end + ft_size((char *)s, c, end);
	}
	tab_s[i_tab] = NULL;
	return (tab_s);
}

char	**ft_split(char const *s, char c)
{
	char	**tab_s;
	int		end;

	if (!s)
		return (NULL);
	end = 0;
	tab_s = malloc(sizeof(char *) * (count_words((char *)s, c) + 1));
	if (!tab_s)
		return (NULL);
	tab_s = ft_splitter(s, c, tab_s, end);
	if (tab_s == NULL)
		return (NULL);
	return (tab_s);
}
