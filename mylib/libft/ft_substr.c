/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:02:37 by dsiroten          #+#    #+#             */
/*   Updated: 2024/02/27 14:40:58 by dsiroten         ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start,
size_t len)
{
	char		*s2;
	size_t		i;

	i = 0;
	if (!ft_strlen(s) || start > ft_strlen(s) - 1 || len <= 0)
		return (empty());
	if (ft_strlen(s) < start + len)
		len = ft_strlen(s) - start;
	s2 = (char *)malloc(len + 1);
	if (!s2)
		return (0);
	while (i < len && s[start])
	{
		s2[i] = s[start];
		start++;
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
