/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:44:39 by dsiroten          #+#    #+#             */
/*   Updated: 2024/04/02 14:44:42 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, const char *format, int count, int i)
{
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			i++;
			if (format[i] == 'c')
				count += (ft_putchar(va_arg(args, int)));
			else if (format[i] == 's')
				count += (ft_putstr(va_arg(args, char *)));
			else if (format[i] == 'p')
				count += (ft_putaddress(va_arg(args, void *)));
			else if (format[i] == 'd' || format[i] == 'i')
				count += (ft_putnbr(va_arg(args, int)));
			else if (format[i] == 'u')
				count += (ft_put_unsigned_int(va_arg(args, unsigned int)));
			else if (format[i] == 'x' || format[i] == 'X')
				count += (ft_puthex(va_arg(args, unsigned int), format[i]));
			else if (format[i] == '%')
				count += ft_putchar('%');
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	args;

	count = 0;
	i = 0;
	va_start(args, format);
	count = ft_format(args, format, count, i);
	va_end(args);
	return (count);
}
