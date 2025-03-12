/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:13:56 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/06/06 17:17:56 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char	const *str, ...)
{
	va_list	ap;
	int		num;

	num = 0;
	va_start(ap, str);
	while (*str)
	{
		if ((*str) == '%')
		{
			num += ft_arg_printf(ap, *++str);
		}
		else
			num += ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (num);
}

int	ft_arg_printf(va_list ap, char chr)
{
	int	res;

	res = 0;
	if (chr == 'c')
		res += ft_putchar(va_arg(ap, int));
	else if (chr == 'd')
		res += ft_putnbr_total(va_arg(ap, int));
	else if (chr == 'i')
		res += ft_putnbr_total(va_arg(ap, int));
	else if (chr == 's')
		res += ft_putstr(va_arg(ap, char *));
	else if (chr == 'x' || chr == 'X')
		res += ft_hexa(va_arg(ap, unsigned int), chr);
	else if (chr == 'p')
	{
		res += ft_putstr("0x") + ft_hexa(va_arg(ap, unsigned long int), chr);
	}
	else if (chr == 'u')
	{
		res += ft_putnbr_unsigned(va_arg(ap, unsigned int));
	}
	else
		if (chr == '%')
			res += ft_putchar('%');
	return (res);
}
