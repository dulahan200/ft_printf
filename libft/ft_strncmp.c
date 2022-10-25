/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 00:50:59 by hmestre-          #+#    #+#             */
/*   Updated: 2022/09/22 19:29:10 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s1[i] != '\0' && i < n -1)
	{
		i++;
	}
	if (n == 0)
	{
		return (0);
	}
	else
		return ((unsigned char)s1[i] - (unsigned char) s2[i]);
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
