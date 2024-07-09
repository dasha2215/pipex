/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:56:15 by dsiroten          #+#    #+#             */
/*   Updated: 2024/02/27 13:49:46 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		full_size;
	int		i;
	char	*ptr;

	i = 0;
	full_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char *)malloc(full_size * sizeof(char));
	if (!ptr)
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	ft_strlcat(ptr, s2, full_size);
	return (ptr);
}
