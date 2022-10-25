/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:27:36 by hmestre-          #+#    #+#             */
/*   Updated: 2022/10/12 16:32:59 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//recursive function that stores an int onto an string and returns it. 
//if malloc fails to allocate memory returns NULL
//

static size_t	ft_count_digits(int n)
{
	size_t	digit_counter;

	digit_counter = 1;
	while (n > 9)
	{
		n = n / 10;
		digit_counter++;
	}
	return (digit_counter);
}

char	*ft_itoa(int n)
{
	char	*nbr_string;
	size_t	digits_n;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	digits_n = ft_count_digits(n);
	nbr_string = malloc(sizeof(char) * (digits_n + 1 - sign));
	if (!nbr_string)
		return (NULL);
	nbr_string[digits_n - sign] = '\0';
	while (digits_n-- - sign)
	{
		nbr_string[digits_n - sign] = (char)((n % 10) + '0');
		n = n / 10;
	}
	if (sign == -1)
		nbr_string[0] = '-';
	return (nbr_string);
}
/*
char	*ft_itoa(int n)
{
	char	*nbr_string;
	size_t	digits_n;
	int		sign;

//	if (n == -2147483648)
//		return (ft_strdup("-2147483648"));
	if (n == INT_MIN)
		return (ft_strdup((char *)INT_MIN));
	sign = 0;
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	digits_n = ft_count_digits(n);
	nbr_string = malloc(sizeof(char) * (digits_n + 1 - sign));
	if (!nbr_string)
		return (NULL);
	nbr_string[digits_n - sign] = '\0';
	while (digits_n-- - sign)
	{
		nbr_string[digits_n - sign] = (char)((n % 10) + '0');
		n = n / 10;
	}
	if (sign == -1)
		nbr_string[0] = '-';
	return (nbr_string);
}*/
