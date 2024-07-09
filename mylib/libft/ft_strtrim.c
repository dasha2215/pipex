/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:40:33 by dsiroten          #+#    #+#             */
/*   Updated: 2024/02/28 14:26:07 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*empty(void)
{
	char	*s;

	s = (char *)malloc(1);
	if (!s)
		return (0);
	*s = '\0';
	return (s);
}

static int	to_trim(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		start;
	int		end;
	int		i;

	end = ft_strlen(s1) - 1;
	start = 0;
	i = 0;
	while (s1[start] && to_trim(s1[start], set))
		start++;
	if (!s1[start])
		return (empty());
	while (s1[end] && to_trim(s1[end], set))
		end--;
	s2 = (char *)malloc((end - start + 2) * sizeof(char));
	if (!s2)
		return (0);
	while (start <= end)
		s2[i++] = s1[start++];
	s2[i] = '\0';
	return (s2);
}
