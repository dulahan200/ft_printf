/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fdbase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:56:02 by hmestre-          #+#    #+#             */
/*   Updated: 2022/11/28 21:07:35 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ATTENTION!!
//BASE = NULL || empty string --> SEGFAULT
//Return value = num of printed char (-1 if failing to write to fd)


#include "libft/libft.h"

unsigned int	ft_putuint_fdbase(unsigned int n, char *base, int fd, int chars)
{
	unsigned int	base_n;
	int				charsdif;

	charsdif = 0;
	if (chars >= 0)
	{
		base_n = ft_strlen(base);
		if (n < base_n)
		{
			charsdif = (ft_putchar_fd(base[n + 48], fd));
		}
		else
		{
			charsdif = ft_putuint_fdbase(n / base_n, base, fd, chars);
			n = n % base_n;
		}
		if (charsdif < 0)
			return (-1);
	}
	return (chars + charsdif);
}
