/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:36:10 by hmestre-          #+#    #+#             */
/*   Updated: 2022/11/29 18:16:39 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

int				ft_printf(const char *str, ...);
int     		ft_putint_fdbase(int n, char *base, int fd);
unsigned int	ft_putuint_fdbase(unsigned int n, char *base, int fd);
//
static unsigned int	ft_ptoadr(void* ptr);
static int ft_printchar(const char c, va_list ap);
int	ft_print_analysis(const char *s, va_list ap);
int	ft_printf(const char *str, ...);
#endif
