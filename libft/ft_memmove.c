/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:23:04 by hmestre-          #+#    #+#             */
/*   Updated: 2022/09/22 21:15:26 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*initial_dst;

	initial_dst = dst;
	if (dst || src)
	{	
		while (len--)
		{
			if (dst <= src)
			*(unsigned char *) dst++ = *(unsigned char *) src++;
			else
			*((unsigned char *) dst + len) = *((unsigned char *) src + len);
		}
	}
	return (initial_dst);
}
