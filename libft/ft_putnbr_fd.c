/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:06:33 by hmestre-          #+#    #+#             */
/*   Updated: 2022/10/25 20:07:54 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//Return value is -1 if failing to write to fd.

//if base = NULL or empty, this is going to segfault. It is the programer's
//duty to check this befpre the call
//
//This function returns negative values with a minus sign, always. If 
//integer overflow is desired, it must be casted as unsigned before the call
//minimum integer conversion is not implemented

int	ft_putnbr_fd(int n, char* base, int fd)
{
	int	base_n;

	base_n = ft_strlen(base);
	if (n == -2147483648 && ft_strncmp(base, "0123456789", 10) == 0)
	{
		if (ft_putstr_fd("-2", fd) == -1)
			return (-1);
		n = 147483648;
	}
	if (n < 0)
	{
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		n *= -1;
	}
	if (n < base_n)
	{
		return (ft_putchar_fd(n + 48, fd));
	}
	else
	{
		ft_putnbr_fd(n / base_n, fd);
		n = n % base_n;
	}
}
