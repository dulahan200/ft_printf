/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:36:10 by hmestre-          #+#    #+#             */
/*   Updated: 2022/11/03 19:57:16 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
//# include "libft.a"  ///
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct printflags
{
	char	mode;
	char	flag_hash;
	char	flag_space;
	char	flag_plus;
}t_printflags;

int	ft_printf(const char *str, ...);
int     ft_putint_fdbase(int n, char *base, int fd);
unsigned int    ft_putuint_fdbase(unsigned int n, char *base, int fd);
#endif
