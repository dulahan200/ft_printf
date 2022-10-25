/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:50:53 by hmestre-          #+#    #+#             */
/*   Updated: 2022/09/25 18:24:04 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (*(ptr1 + i) - *(ptr2 + i));
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	unsigned int size;
	char	s1[] = "gfda";
	char	s2[]= "gfdbgdfgfd";

	size = 4;
printf("%d\n",ft_strncmp(s1, s2, size));
printf("%d",strncmp(s1, s2, size));
}*/
