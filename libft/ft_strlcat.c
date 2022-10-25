/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 02:06:14 by hmestre-          #+#    #+#             */
/*   Updated: 2022/09/22 17:49:36 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *restrict dest, t_cchar *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	dest_len = 0;
	src_len = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (dstsize != 0)
	{
		while (src[i] && (i + dest_len < dstsize - 1))
		{
			dest[i + dest_len] = src[i];
			i++;
		}
		dest[i + dest_len] = '\0';
	}	
	if (dstsize < dest_len)
		dest_len = dstsize;
	return (dest_len + src_len);
}
/*
int	main(void)
{
	char * str1 = malloc(19 * sizeof(char));
		str1[0] = 'a';
		str1[1] = 'b';
		str1[2] = 'c';
		str1[3] = '\0';
	char str2[] = "Tomi";
	size_t size;
	char *str1bis = malloc (20 *sizeof(char));
	char *str2bis = malloc (20 *sizeof(char));
	str1bis = strcpy(str1bis,str1);
	str2bis = strcpy(str2bis,str2);
	int r1;
	int	r2;

	size = 5;
	r1 = ft_strlcat(str1, str2, size);
	puts(str1);
	printf(" ft =  %d\n\n", r1);
	r2 = strlcat(str1bis, str2bis, size);
	puts(str1bis);
	printf(" original =  %d", r2);
}*/
