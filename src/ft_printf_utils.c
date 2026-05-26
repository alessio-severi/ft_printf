/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 18:27:16 by aseveri           #+#    #+#             */
/*   Updated: 2026/05/13 03:12:56 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (!(char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

int	ft_print_number(unsigned long number, const char *base, int *flag)
{
	int				len;
	char			c;
	unsigned long	len_base;

	len = 0;
	*flag = 0;
	len_base = ft_strlen(base);
	if (number >= len_base)
		len += ft_print_number(number / len_base, base, flag);
	c = base[number % len_base];
	if (*flag != -1 && write(1, &c, 1) != -1)
		return (++len);
	return (*flag = -1, 0);
}

int	ft_putnbr(int n, int *flag)
{
	long	number;
	int		len;

	number = n;
	len = 0;
	if (number < 0)
	{
		if (write(1, "-", 1) == -1)
			return (*flag = -1, 0);
		number = -number;
		len++;
	}
	len += ft_print_number((unsigned long) number, "0123456789", flag);
	return (len);
}
