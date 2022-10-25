/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:34:40 by hmestre-          #+#    #+#             */
/*   Updated: 2022/10/10 18:34:55 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
// Copies up to dstsize characters of the src string
//  onto the dest string, and null terminates it

size_t	ft_strlcpy(char *dest, t_cchar *src, size_t dstsize)
{
	size_t	i;
	size_t	size_src;

	size_src = 0;
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] && i < (dstsize -1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[size_src])
	{
		size_src++;
	}
	return (size_src);
}
