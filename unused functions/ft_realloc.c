/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:56:55 by hmestre-          #+#    #+#             */
/*   Updated: 2022/10/17 19:36:59 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

void	ft_realloc(void *ptr, size_t size)
{
	char	*tmp_ptr;

	if (!size)
		ptr = NULL;
	if (ptr == NULL)
		return ;
	tmp_ptr = malloc(size);
	if (!tmp_ptr)
		return ;
	ft_memcpy(tmp_ptr, ptr, size);
	free(ptr);
	ptr = tmp_ptr;
	free(tmp_ptr);
}
