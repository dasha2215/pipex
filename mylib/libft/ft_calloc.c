/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:57:55 by dsiroten          #+#    #+#             */
/*   Updated: 2024/02/28 14:34:41 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	if (size && 4294967295 / size < count)
		return (0);
	arr = malloc(count * size);
	if (arr == 0)
		return (arr);
	ft_bzero(arr, size * count);
	return (arr);
}
