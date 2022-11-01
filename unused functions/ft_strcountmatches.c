/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcountmatches.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:14:49 by hmestre-          #+#    #+#             */
/*   Updated: 2022/10/17 19:37:22 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	countmatches(const char *str, char c)
{
	size_t	num_matches;
	size_t	i;

	if (!str || !c)
		return (0);
	i = 0;
	while (i < ft_strlen(str))
	{
		if (s[i] == c)
			num_matches++;
		i++;
	}
	return (num_matches);
}
