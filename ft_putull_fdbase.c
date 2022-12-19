/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putull_fdbase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:43:41 by hmestre-          #+#    #+#             */
/*   Updated: 2022/12/19 19:49:10 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
ATTENTION!!
BASE = NULL || empty string --> SEGFAULT
Return value = num of printed char (-1 if failing to write to fd)

INPUT ARGUMENTS

n = number to print in file descriptor fd
fd = file descriptor
base = 0123456789, 0123456789abcdef, etc.
*/

#include "ft_printf.h"

unsigned int	ft_putull_fdbase(t_ull n, char *base, int fd)
{
	unsigned int	base_n;
	int				charsdif;
	int				tmp;

	charsdif = 0;

	base_n = ft_strlen(base);
	if (n < base_n)
	{
		charsdif = (ft_putchar_fd(base[n], fd));
	}
	else
	{
		charsdif = ft_putull_fdbase(n / base_n, base, fd);
		if (charsdif == -1)
			return (-1);
		tmp = ft_putull_fdbase(n % base_n, base, fd);
		if (tmp == -1)
			return (-1);
		charsdif = charsdif + tmp;
	}
	return (charsdif);
}
