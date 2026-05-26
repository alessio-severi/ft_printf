/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 18:02:54 by aseveri           #+#    #+#             */
/*   Updated: 2026/05/13 02:32:43 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(va_list *opt_params, int *flag)
{
	unsigned char	arg;

	arg = (unsigned char) va_arg(*opt_params, int);
	if (write(1, &arg, 1) == -1)
		return (*flag = -1, 0);
	return (*flag = 0, 1);
}

int	ft_print_s(va_list *opt_params, int *flag)
{
	int			len;
	const char	*str;

	str = va_arg(*opt_params, char *);
	if (!str)
		str = "(null)";
	len = (int) ft_strlen(str);
	if (write(1, str, len) == -1)
		return (*flag = -1, 0);
	return (*flag = 0, len);
}

int	ft_print_percent(va_list *opt_params, int *flag)
{
	(void) opt_params;
	if (write(1, "%", 1) == -1)
		return (*flag = -1, 0);
	return (*flag = 0, 1);
}
