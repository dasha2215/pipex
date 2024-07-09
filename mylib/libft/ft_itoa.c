/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:22:46 by dsiroten          #+#    #+#             */
/*   Updated: 2024/02/28 13:32:53 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_nums(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		n = n / 10;
		len++;
	}
	len += 2;
	return (len);
}

static char	*zero(void)
{
	char	*nb;

	nb = (char *)malloc(2);
	if (!nb)
		return (0);
	nb[0] = '0';
	nb[1] = '\0';
	return (nb);
}

static char	*smallest(long int n)
{
	char	*nb;
	int		len;

	len = 10;
	nb = (char *)malloc(12);
	if (!nb)
		return (0);
	nb[len + 1] = '\0';
	while (len > 0)
	{
		nb[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	nb[len] = '-';
	return (nb);
}

static void	write_num(char *nb, int n, int len)
{
	nb[len] = '\0';
	len--;
	while (len >= 0)
	{
		if (nb[len] == '-')
			return ;
		nb[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char	*nb;
	int		len;

	if (n == 0)
		return (zero());
	if (n == -2147483648)
		return (smallest(2147483648));
	len = count_nums(n);
	nb = (char *)malloc(len * sizeof(char));
	if (!nb)
		return (0);
	if (n < 0)
	{
		nb[0] = '-';
		n = -n;
	}
	write_num(nb, n, len - 1);
	return (nb);
}
