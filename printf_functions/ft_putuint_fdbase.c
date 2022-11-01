/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fdbase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:56:02 by hmestre-          #+#    #+#             */
/*   Updated: 2022/11/01 20:07:35 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ATTENTION!!
//BASE = NULL || empty string --> SEGFAULT
//Return value = num of printed char (-1 if failing to write to fd)

#include "libft.h"

unsigned int	ft_putuint_fdbase(unsigned int n, char *base, int fd)
{
	unsigned_int	base_n;

	base_n = ft_strlen(base);
	if (n < base_n)
	{
		return (ft_putchar_fd(base[n + 48], fd));
	}
	else
	{
		ft_putnbr_fd(n / base_n, base, fd);
		n = n % base_n;
	}
}
