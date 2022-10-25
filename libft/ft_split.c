/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:10:41 by hmestre-          #+#    #+#             */
/*   Updated: 2022/10/05 21:52:07 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_free_2darray(char **s, size_t arr_size)
{
	size_t	i;

	i = 0;
	while (i < arr_size)
		free(s[i++]);
	free(s);
}

static size_t	countwords(char const *s, char c)
{
	size_t	num_words;
	size_t	i;

	i = 0;
	num_words = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			num_words++;
		if (i > 0 && s[i] != c && s[i - 1] == c)
			num_words++;
		i++;
	}
	return (num_words);
}

static int	ft_splitstring(char **res, const char *s, char c)
{
	size_t	i;
	int		j;
	size_t	start;

	j = 0;
	i = 0;
	start = 0;
	while (i < ft_strlen(s))
	{
		if ((i > 0 && s[i] != c && s[i - 1] == c) || (i == 0 && s[i] != c))
			start = i;
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
		{
			res[j] = ft_substr(s, start, i + 1 - start);
			if (res[j] == NULL)
			{
				ft_free_2darray(res, j);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	words = countwords(s, c);
	res = (char **)malloc((words + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	if (ft_splitstring(res, s, c) == -1)
		return (NULL);
	res[words] = (NULL);
	return (res);
}
