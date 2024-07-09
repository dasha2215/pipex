/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:55:17 by dsiroten          #+#    #+#             */
/*   Updated: 2024/02/27 14:05:45 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p)
	{
		if ((unsigned char)*p == (unsigned char) c)
			return (p);
		p++;
	}
	if ((unsigned char)*p == (unsigned char) c)
		return (p);
	return (0);
}
