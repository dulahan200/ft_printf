/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_fdbase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:56:21 by hmestre-          #+#    #+#             */
/*   Updated: 2023/01/24 18:44:32 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ATTENTION!!
//BASE = NULL || empty string --> SEGFAULT
//Return value = num of printed chars
#include "ft_printf.h"

int	ft_putint_fdbase(int n, char *base, int fd);

static int	ft_putint_min(int n, char *base, int base_n, int fd)
{
	int	charsdif;
	int	tmp;

	if (ft_putchar_fd('-', fd) == -1)
		return (-1);
	tmp = ft_putint_fdbase(-1 * (n / base_n), base, fd);
	if (tmp == -1)
		return (-1);
	charsdif = 1 + tmp;
	tmp = ft_putint_fdbase(-1 * (n % base_n), base, fd);
	if (tmp == -1)
		return (-1);
	charsdif = charsdif + tmp;
	return (charsdif);
}

int	ft_putint_fdbase(int n, char *base, int fd)
{
	int	base_n;
	int	charsdif;
	int	tmp;

	charsdif = 0;
	base_n = ft_strlen(base);
	if (n == INT_MIN)
		return (ft_putint_min(n, base, base_n, fd));
	else if (n < 0)
	{
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		tmp = ft_putuint_fdbase((t_ui)(-n), base, fd);
		if (tmp == -1)
			return (-1);
		charsdif = 1 + tmp;
	}
	else
	{
		charsdif = ft_putuint_fdbase((t_ui) n, base, fd);
		if (charsdif == -1)
			return (-1);
	}
	return (charsdif);
}

/* this function is cleaner but does not pass norminette
 * (has more than 25 lines)
int	ft_putint_fdbase(int n, char *base, int fd)
{
	int	base_n;
	int	charsdif;
	int	tmp;

	charsdif = 0;
	base_n = ft_strlen(base);
	if (n == INT_MIN)
		return (ft_putint_min(n, base, base_n, fd));
	else if (n < 0)
	{
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		tmp = ft_putint_fdbase( -n, base, fd);
		if (tmp == -1)
			return (-1);
		charsdif = 1 + tmp;
	}
	else if (n < base_n)
	{
		tmp = ft_putchar_fd(base[n], fd);
		if (tmp == -1)
			return (-1);
		charsdif = charsdif + tmp;
	}
	else
	{
		tmp = ft_putint_fdbase(n / base_n, base, fd);
		if (tmp == -1)
			return (-1);
		charsdif = charsdif + tmp;
		tmp = ft_putint_fdbase(n % base_n, base, fd);
		if (tmp == -1)
			return (-1);
		charsdif = charsdif + tmp;
	}
	return (charsdif);
}*/
