/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:31:31 by hmestre-          #+#    #+#             */
/*   Updated: 2022/10/10 17:36:47 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

// *s = initial string. start = beginning new string, len = length of string
// must check for mallocs after calling (returns NULL)
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;
	size_t	len_s;

	len_s = ft_strlen(s);
	i = 0;
	if (start >= len_s)
		sub_str = malloc(sizeof(char) * 1);
	else if (len >= len_s - start + 1)
		sub_str = malloc(sizeof(char) * (len_s - start + 1));
	else
		sub_str = malloc(sizeof(char) * (len + 1));
	if (sub_str == NULL)
		return (NULL);
	while (start + i < len_s && i < len)
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
