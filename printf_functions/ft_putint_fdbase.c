/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_fdbase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:56:21 by hmestre-          #+#    #+#             */
/*   Updated: 2022/11/01 20:07:23 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ATTENTION!!
//BASE = NULL || empty string --> SEGFAULT
//MIN_INT NOT IMPLEMENTED
//Return value = num of printed char (-1 if write fails, -2 if writting nothing)

#include "libft.h"

int	ft_putint_fdbase(int n, char *base, int fd)
{
	int	base_n;

	base_n = ft_strlen(base);
	if (n < 0)
	{
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		n *= -1;
	}
	if (n < base_n)
	{
		return (ft_putchar_fd(base[n + 48], fd));
	}
	else
	{
		ft_putnbr_fd(n / base_n, base, fd);
		n = n % base_n;
	}
	return (-2);
}
