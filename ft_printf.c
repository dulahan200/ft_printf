/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:29:18 by hmestre-          #+#    #+#             */
/*   Updated: 2022/11/07 17:53:54 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"


static void	ft_iniprintflags(t_printflags * flags)
{
	flags->mode = 't';
	flags->flag_hash = 0;
	flags->flag_space = 0;
	flags->flag_plus = 0;
}

static unsigned int	ft_p2adr(void* ptr)
{
	if (!ptr)
		return (-1);

		return ((unsigned long long) ptr);
	//	return (ft_putnbr_fd(ptr, 1));
}

static int ft_printchar(char c, t_printflags flags, va_list ap)
{
	if (c == 'c' || c =='%')
		return (ft_putchar_fd(va_arg(ap, int), 1));
	if (c == 's')
		return (ft_putstr_fd(va_arg(ap, char*), 1));
	if (c == 'p')
		return (ft_putuint_fdbase(ft_p2adr(va_arg(ap, void*)), "0123456789abcdef", 1));
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

static void	ft_print_analysis(char *s, t_printflags flags, va_list ap)
{
	int		i;

	i = -1;
	while (s[i++])
	{
		if	(flags.mode == 'r')
		{
			if (s[i]== '%')
				ft_iniprintflags(&flags);	
			else
				write(1, &s[i], 1);
		}
		else
	
		{
			if (ft_strchr("cspdiuxX", s[i]))
				ft_printchar(s[i], flags, ap);
			else if(s[i] == '#')
				flags.flag_hash = 1;
			else if(s[i] == ' ')
				flags.flag_space= 1;
			else if(s[i] == '+')
				flags.flag_plus = 1;
		}
	}
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	t_printflags	flags;

	ft_iniprintflags(&flags);
	flags.mode = 'r';
	va_start(ap, str);
	ft_print_analysis(va_arg(ap, char *), flags, ap);


	va_end(ap);
	return (3);
}
