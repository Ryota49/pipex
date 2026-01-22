/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:58:58 by jemonthi          #+#    #+#             */
/*   Updated: 2025/11/02 17:52:50 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_concatenate_two(char *new, char *s3, size_t i, size_t total_len)
{
	size_t	j;

	total_len = total_len + ft_strlen(s3);
	j = 0;
	while (i < total_len)
	{
		new[i] = s3[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

static char	*ft_concatenate(char *new_string, char *s1, char *s2, char *s3)
{
	size_t	i;
	size_t	j;
	size_t	total_len;

	i = 0;
	j = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	while (i < total_len)
	{
		while (s1[i])
		{
			new_string[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			new_string[i] = s2[j];
			i++;
			j++;
		}
	}
	new_string[i] = '\0';
	new_string = ft_concatenate_two(new_string, s3, i, total_len);
	return (new_string);
}

char	*ft_strjoin(char *s1, char *s2, char *s3)
{
	char	*new_string;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	new_string = malloc(sizeof(char) * total_len + 1);
	if (!new_string)
		return (NULL);
	new_string = ft_concatenate(new_string, s1, s2, s3);
	return (new_string);
}
