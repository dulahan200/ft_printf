/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:29:18 by hmestre-          #+#    #+#             */
/*   Updated: 2022/10/24 21:30:03 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

flags[0]='t' transform: if ft_print is doing a conversion (after a % char)
flags[0]= 'r' read: either print the char or define the start of a conversion
flags[n] = any char within the implemented features, in any order



void	ini_printflags(* struct printflags flags)
{
	flags->mode = 'r';
	flags->flag_# = 0;
	flags->flag_space = 0;
	flags->flag_+ = 0;
}

void	ft_print_analysis(char flags, char c)
{
	if	(flags[0] == 'r')
	{
		if (c == %)
			flags.mode = 't';
		else
			write(1, &c, 1);
	}
	else
		if (ft_strchr(cspdiuxX, c)
		{
			ft_printchar(flags, c);
			ini_printflags(flags);	
		}
		else if(ft_strchr(# +, c)
}


int	ft_printf(const char *str, ...)		//el prototipo del enunciado no dice nada de str, pero me han dicho que lo ponga asi
{
	va_list		ap;
	char	*flags;
	char

	ini_printflags(flags);
	flags.mode = 'r';
	va_start(ap, str);
	ft_print_analysis(flags, va_arg(ap, char *));


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
