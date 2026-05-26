/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 00:33:31 by aseveri           #+#    #+#             */
/*   Updated: 2026/05/13 03:13:41 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_print_number(unsigned long number, const char *base, int *flag);
int		ft_putnbr(int n, int *flag);

int		ft_print_c(va_list *opt_params, int *flag);
int		ft_print_s(va_list *opt_params, int *flag);
int		ft_print_percent(va_list *opt_params, int *flag);

int		ft_print_d(va_list *opt_params, int *flag);
int		ft_print_u(va_list *opt_params, int *flag);
int		ft_print_hex_lower(va_list *opt_params, int *flag);
int		ft_print_hex_upper(va_list *opt_params, int *flag);
int		ft_print_p(va_list *opt_params, int *flag);

#endif
