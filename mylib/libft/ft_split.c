/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:01:48 by dsiroten          #+#    #+#             */
/*   Updated: 2024/02/28 14:30:50 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_wrds(char const *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	if (s[i] != c && s[i])
		words++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			words++;
		i++;
	}
	return (words);
}

char	**free_ptr(char **ptr, int i)
{
	int	j;

	j = 0;
	while (j <= i)
	{
		free(ptr[j]);
		j++;
	}
	free(ptr);
	return (0);
}

char	**make_ptr(const char *s, char c)
{
	char	**ptr;

	if (!s)
		return (0);
	ptr = (char **)malloc((count_wrds(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (0);
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	size_t	start;
	size_t	len;

	i = -1;
	start = 0;
	ptr = make_ptr(s, c);
	if (!ptr)
		return (0);
	while (++i < count_wrds(s, c))
	{
		len = 0;
		while (s[start] == c)
			start++;
		while (s[start + len] != c && s[start + len])
			len++;
		ptr[i] = ft_substr(s, start, (unsigned int)len);
		if (!ptr[i])
			return (free_ptr(ptr, i));
		start += len;
	}
	ptr[i] = 0;
	return (ptr);
}
