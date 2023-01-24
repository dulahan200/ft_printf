/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:29:18 by hmestre-          #+#    #+#             */
/*   Updated: 2023/01/24 17:58:44 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printchar(const char c, va_list ap)
{
	int	tmp;

	if (c == 'c')
		return (ft_putchar_fd(va_arg(ap, int), 1));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(ap, char *), 1));
	else if (c == 'p')
	{
		if (ft_putstr_fd("0x", 1) == -1)
			return (-1);
		tmp = ft_putull_fdbase(va_arg(ap, t_ull), "0123456789abcdef", 1);
		if (tmp > 0)
			return (tmp + 2);
		return (-1);
	}
	else if (c == 'i' || c == 'd')
		return (ft_putint_fdbase(va_arg(ap, int), "0123456789", 1));
	else if (c == 'u')
		return (ft_putuint_fdbase(va_arg(ap, int), "0123456789", 1));
	else if (c == 'x')
		return (ft_putuint_fdbase(va_arg(ap, t_ui), "0123456789abcdef", 1));
	else if (c == 'X')
		return (ft_putuint_fdbase(va_arg(ap, t_ui), "0123456789ABCDEF", 1));
	return (-2);
}

int	ft_print_analysis(const char *s, va_list ap)
{
	int		i;
	char	mode;
	int		chars_printed;
	int		tmp;

	mode = 'r';
	i = -1;
	chars_printed = 0;
	while (s[++i])
	{
		if (mode == 'r')
			if (s[i] == '%')
				mode = 't';
		else
		{
			if (write(1, &s[i], 1) == -1)
				return (-1);
			chars_printed++;
		}
		else
			if (ft_strchr("cspdiuxX%", s[i]))
			{
				tmp = ft_printchar(s[i], ap);
				if (tmp == -1)
					return (-1);
				chars_printed = chars_printed + tmp;
				mode = 'r';
			}
		else
		{
			write(1, "wrong flags", 11);
			return(-1);
		}
	}
	return (chars_printed);
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	int				chars_printed;

	va_start(ap, str);
	chars_printed = ft_print_analysis(str, ap);
	va_end(ap);
	return (chars_printed);
}
