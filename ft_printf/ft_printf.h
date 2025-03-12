/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:15:54 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/06/06 17:21:42 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

/* MAIN FUNCTIONS */

int	ft_printf(char const *str, ...);
int	ft_arg_printf(va_list ap, char chr);

/* EXTRA FUNCTIONS */

int	ft_putchar(char c);
int	ft_putstr(char	*str);
int	ft_hexa(unsigned long int numb, char chr);
int	ft_putnbr_unsigned(unsigned int numb);
int	ft_putnbr_total(int nb);

#endif
