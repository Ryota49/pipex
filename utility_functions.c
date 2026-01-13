/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:18:22 by jemonthi          #+#    #+#             */
/*   Updated: 2025/12/17 22:58:50 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

static char	*sub_string(char const *s, char *li_s, unsigned int st, size_t l)
{
	size_t	i;

	i = 0;
	while (s[st] && i < l)
	{
		li_s[i] = s[st];
		st++;
		i++;
	}
	li_s[i] = '\0';
	return (li_s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*little_s;

	if (!s)
		return (NULL);
	if (len > ft_strlen((char *)s) - start)
		len = ft_strlen((char *)s) - start;
	if (s == 0 || start > ft_strlen((char *)s))
	{
		little_s = malloc(sizeof(char));
		if (!little_s)
			return (NULL);
		little_s[0] = '\0';
		return (little_s);
	}
	little_s = malloc(sizeof(char) * len + 1);
	if (!little_s)
		return (NULL);
	little_s = sub_string(s, little_s, start, len);
	return (little_s);
}
