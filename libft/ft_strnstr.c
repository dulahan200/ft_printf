/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:44:50 by hmestre-          #+#    #+#             */
/*   Updated: 2022/09/22 16:10:03 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cn;
	size_t	ch;

	ch = 0;
	cn = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[ch] && ch < len)
	{
		while (haystack[ch + cn] == needle[cn] && (ch + cn < len))
		{
			if (needle[cn + 1] == '\0')
			{
				return (&((char *)haystack)[ch]);
			}
				cn++;
		}
	ch++;
	cn = 0;
	}
	return (NULL);
}
/*
int	main(void)
{
//	char	s1[] = "adeu";
char	s1[] = "hola adeu i dema";
	char	s2[]= "adeu";
ft_strnstr(s1, s2, 9);
//printf("%s\n",ft_strnstr(s1, s2, 9));
}*/
