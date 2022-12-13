/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_fdbase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:56:21 by hmestre-          #+#    #+#             */
/*   Updated: 2022/12/13 18:38:07 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ATTENTION!!
//BASE = NULL || empty string --> SEGFAULT
//MIN_INT NOT IMPLEMENTED
//Return value = num of printed char (-1 if write fails, -2 if writting nothing)

#include "libft/libft.h"

int	ft_putint_fdbase(int n, char *base, int fd)
{
	int	base_n;
	int	charsdif;

	charsdif = 0;
		base_n = ft_strlen(base);
		if (n == INT_MIN)
			charsdif = ft_putstr_fd(INT_MIN);
		if (n < 0)
		{
			if (ft_putchar_fd('-', fd) == -1)
				return (-1);
			charsdif = ft_putint_fdbase(-n, base, fd);
		}
		else if (n < base_n)
			charsdif = ft_putchar_fd(base[n], fd);
		else
		{
			charsdif = ft_putint_fdbase(n / base_n, base, fd);
			charsdif = charsdif + ft_putint_fdbase(n % base_n, base, fd);
		}
		if (charsdif < 0)
			return (-1);
	return (charsdif);
}
