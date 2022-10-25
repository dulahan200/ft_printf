/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:29:18 by hmestre-          #+#    #+#             */
/*   Updated: 2022/10/25 20:07:49 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_ini_printflags(* struct printflags flags)
{
	flags->mode = 't';
	flags->flag_hash = 0;
	flags->flag_space = 0;
	flags->flag_+ = 0;
}

static int ft_printchar(char c, t_printflags flags, va_list ap)
{
	if (c == 'c' || c =='%')
		return (write(1, va_arg(ap, char) ,1));
	if (c == 's')
		return (ft_putstr_fd(va_arg(ap, char*), 1));
	if (c == 'p')
		return (ft_putnbr_fd(va_arg(ap, void*), "0123456789", 1); ///tengo que testear esto para entenderlo bien
	if (c == 'i'|| c == 'd')
		return (ft_putnbr_fd(va_arg(ap, int), "0123456789", 1);
	if (c == 'u')   
		return (ft_putnbr_fd((va_arg(ap, unsigned int), "0123456789", 1));
	if (c == 'x') //hexadecimal lowercase
		return (ft_putnbr_fd((va_arg(ap, unsigned int), "0123456789abcdef", 1));
	if (c == 'X') //hexadecimal uppercase
		return (ft_putnbr_fd((va_arg(ap, unsigned int), "0123456789ABCDEF", 1));
}

static void	ft_print_analysis(char *s, t_printflags, va_list ap)
{
	int		i;
	char	*s;

	i = -1;
	while (s[i++])
	{
		if	(flags.mode == 'r')
		{
			if (s[i]== %)
				ini_printflags(flags);	
			else
				write(1, &s[i], 1);
		}
		else
		{
			if (ft_strchr("cspdiuxX", s[i])
				ft_printchar(s[i], flags, ap);
			else if(s[i] == '#')
				flags.flag_hash = 1;
			else if(s[i] == ' ')
				flags.flag_space= 1;
			else if(s[i] == '+')
				flags.flag_+ = 1;
		}
}


int	ft_printf(const char *str, ...)		//el prototipo del enunciado no dice nada de str, pero me han dicho que lo ponga asi
{
	va_list			ap;
	t_printflags	flags;

	ft_ini_printflags(flags);
	flags.mode = 'r';
	va_start(ap, str);
	ft_print_analysis(ap, flags, va_arg(ap, char *));
	ft_print_analysis(va_arg(ap, char *), flags, ap);


	va_end(ap);
	return (3);
}

/*
	*input = va_arg(ap, char *);
	returned_vars = ft_countmatches(*input, %);
	while (var_case
	input = ft_realloc(input, va_arg(ap, char *);
	va_end(ap);
	*/
