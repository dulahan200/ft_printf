/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:29:18 by hmestre-          #+#    #+#             */
/*   Updated: 2022/11/29 18:57:26 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_ptoadr(void* ptr)
{
	if (!ptr)
		return (-1);

		return ((unsigned long long) ptr);
	//	return (ft_putnbr_fd(ptr, 1));
}

static int ft_printchar(const char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(ap, int), 1)); 
	if (c == '%')
		return (ft_putchar_fd('%', 1)); 
	if (c == 's')
		return (ft_putstr_fd(va_arg(ap, char*), 1));
	if (c == 'p')
		return (ft_putuint_fdbase(ft_ptoadr(va_arg(ap, void*)), "0123456789abcdef", 1));
	if (c == 'i'|| c == 'd')
		return (ft_putnbr_fd(va_arg(ap, int), 1));
	if (c == 'u')   
		return (ft_putnbr_fd(va_arg(ap, unsigned int), 1));
	if (c == 'x') //hexadecimal lowercase
		return (ft_putuint_fdbase(va_arg(ap, unsigned int), "0123456789abcdef", 1));
	if (c == 'X') //hexadecimal uppercase
		return (ft_putuint_fdbase(va_arg(ap, unsigned int), "0123456789ABCDEF", 1));
	return(-2);
}

int	ft_print_analysis(const char *s, va_list ap)
{
	int		i;
	char	mode;
	int		chars_printed;

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
//				printf("time%d\n", i);
				if (ft_printchar(s[i], ap) == -1)
					return(-1);
//				printf("time%d\n", i);
				chars_printed++;
				mode = 'r';
			}
	}
	return (chars_printed);
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	int		chars_printed;

	va_start(ap, str);
	chars_printed = ft_print_analysis(str, ap);
	va_end(ap);
	return (chars_printed);
}
