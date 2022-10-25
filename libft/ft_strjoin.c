/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:42:50 by hmestre-          #+#    #+#             */
/*   Updated: 2022/09/29 16:44:08 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s2_len;
	size_t	s1_len;
	char	*res;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *) malloc (sizeof(char) * (s1_len + s2_len + 1));
	if (res == NULL)
		return (NULL);
	while (i < s1_len)
	{
		res[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		res[i] = s2[i - s1_len];
		i++;
	}
	res[i] = '\0';
	return (res);
}
