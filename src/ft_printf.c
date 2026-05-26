/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 21:15:33 by aseveri           #+#    #+#             */
/*   Updated: 2026/05/13 02:20:58 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	(*ft_dispatcher(const char op))(va_list *opt_params, int *flag)
{
	const char	*formats;
	int			(*operators[9])(va_list *opt_params, int *flag);
	int			i;

	formats = "cspdiuXx%";
	operators[0] = ft_print_c;
	operators[1] = ft_print_s;
	operators[2] = ft_print_p;
	operators[3] = ft_print_d;
	operators[4] = ft_print_d;
	operators[5] = ft_print_u;
	operators[6] = ft_print_hex_upper;
	operators[7] = ft_print_hex_lower;
	operators[8] = ft_print_percent;
	i = -1;
	while (++i < 9)
		if (op == formats[i])
			return (operators[i]);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	opt_params;
	int		len;
	int		flag;

	if (!format)
		return (0);
	len = 0;
	va_start(opt_params, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (!*(format + 1) || !ft_strchr("cspdiuXx%", (int)*(format + 1)))
				flag = write(1, "%", 1);
			else
				len += ft_dispatcher(*++format)(&opt_params, &flag) - 1;
		}
		else
			flag = write(1, format, 1);
		if (flag == -1)
			return (va_end(opt_params), -1);
		len++;
		format++;
	}
	return (va_end(opt_params), len);
}
