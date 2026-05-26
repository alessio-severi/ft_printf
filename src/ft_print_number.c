/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 18:57:37 by aseveri           #+#    #+#             */
/*   Updated: 2026/05/13 02:47:29 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_d(va_list *opt_params, int *flag)
{
	return (ft_putnbr(va_arg(*opt_params, int), flag));
}

int	ft_print_u(va_list *opt_params, int *flag)
{
	return (ft_print_number(va_arg(*opt_params, unsigned int),
			"0123456789", flag));
}

int	ft_print_hex_upper(va_list *opt_params, int *flag)
{
	return (ft_print_number(va_arg(*opt_params, unsigned int),
			"0123456789ABCDEF", flag));
}

int	ft_print_hex_lower(va_list *opt_params, int *flag)
{
	return (ft_print_number(va_arg(*opt_params, unsigned int),
			"0123456789abcdef", flag));
}

int	ft_print_p(va_list *opt_params, int *flag)
{
	unsigned long	addr;

	addr = (unsigned long)va_arg(*opt_params, void *);
	if (!addr)
	{
		if (write(1, "(nil)", 5) == -1)
			return (*flag = -1, 0);
		return (*flag = 0, 5);
	}
	if (write(1, "0x", 2) == -1)
		return (*flag = -1, 0);
	return (2 + ft_print_number(addr, "0123456789abcdef", flag));
}
