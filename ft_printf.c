/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:29:18 by hmestre-          #+#    #+#             */
/*   Updated: 2022/10/24 22:31:55 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_ini_printflags(* struct printflags flags)
{
	flags->mode = 't';
	flags->flag_# = 0;
	flags->flag_space = 0;
	flags->flag_+ = 0;
}

static void ft_printchar(char c, t_printflags flags, char* s)
{
	if (c == 'c' || c =='%')
		write(1, &s[0] ,1);
	if (c == 's')
		ft_putstr_fd(s, 1);
	if (c == 'p')
		ft_putnbr_fd(atoi(&s), 1);
	if (c == 'd')    //decimal number, have to think
	if (c == 'i')
		ft_putnbr_fd(atoi(s), 1);
	if (c == 'u')   //unsigned decimal
	if (c == 'x') //hexadecimal lowercase
		{
			atoi(x);
	if (c == 'X') //hexadecimal uppercase
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
				ft_printchar(s[i], flags, va_arg(ap, char*));
			else if(s[i] == '#')
				flags.flag_# = 1;
			else if(s[i] == ' ')
				flags.flag_space= 1;
			else if(s[i] == '+')
				flags.flag_+ = 1;
		}
}


int	ft_printf(const char *str, ...)		//el prototipo del enunciado no dice nada de str, pero me han dicho que lo ponga asi
{
	va_list			ap;
	char			*flags;
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
