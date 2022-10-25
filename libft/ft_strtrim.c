/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:46:12 by hmestre-          #+#    #+#             */
/*   Updated: 2022/10/10 19:59:08 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//this could have been far easier (and faster) using strchr and strrchr to
//locate the start and end, then make a substring.

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_string;
	size_t	i;
	size_t	end;

	if (!s1 || !set)
		return ((char *)s1);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (*s1 && ft_strrchr(set, s1[i]))
		i--;
	end = i + 1;
	trimmed_string = ft_substr(s1, 0, end);
	return (trimmed_string);
}
