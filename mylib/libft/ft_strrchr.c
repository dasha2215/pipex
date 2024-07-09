/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:00:03 by dsiroten          #+#    #+#             */
/*   Updated: 2024/02/27 14:09:43 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	*pp;

	p = (char *)s;
	pp = 0;
	while (*p)
	{
		if ((unsigned char)*p == (unsigned char) c)
			pp = p;
		p++;
	}
	if ((unsigned char)*p == (unsigned char) c)
		return (p);
	return (pp);
}
