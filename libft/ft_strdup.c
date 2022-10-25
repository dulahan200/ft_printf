/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:35:51 by hmestre-          #+#    #+#             */
/*   Updated: 2022/10/10 18:34:34 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	s2_size;

	s2_size = ft_strlen(s1);
	s2 = (char *) malloc(s2_size + 1);
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, s1, s2_size + 1);
	return (s2);
}
