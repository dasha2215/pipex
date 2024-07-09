/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:57:46 by dsiroten          #+#    #+#             */
/*   Updated: 2024/05/13 16:01:51 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_within_limits(char c, long result, int m)
{
	if (result * m > INT_MAX / 10 || (result * m == (INT_MAX / 10)
			&& (c - '0') > (INT_MAX % 10)))
		return (0);
	if (result * m < INT_MIN / 10 || (result * m == (INT_MIN / 10)
			&& (c - '0') * m < (INT_MIN % 10)))
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int			i;
	long		result;
	int			m;

	i = 0;
	result = 0;
	m = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			m *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (!is_within_limits(str[i], result, m))
			return (0);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return (result * m);
}
