/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:45:13 by dsiroten          #+#    #+#             */
/*   Updated: 2024/04/02 14:45:15 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	ft_putaddress(void *p)
{
	int				count;
	unsigned long	n;

	count = 0;
	if (p)
	{
		count += ft_putstr("0x");
		n = (unsigned long) p;
		count += ft_puthex(n, 'x');
	}
	else
		count = ft_putstr("(nil)");
	return (count);
}
