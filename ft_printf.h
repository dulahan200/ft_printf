/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:36:10 by hmestre-          #+#    #+#             */
/*   Updated: 2023/01/24 19:30:00 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef unsigned long long	t_ull;
typedef unsigned int		t_ui;
int							ft_printf(const char *str, ...);
int							ft_putint_fdbase(int n, char *base, int fd);
unsigned int				ft_putuint_fdbase(t_ui n, char *base, int fd);
unsigned int				ft_putull_fdbase(t_ull n, char *base, int fd);
//
//static unsigned int	ft_ptoadr(void* ptr);
//static int ft_printchar(const char c, va_list ap);
int							ft_print_analysis(const char *s, va_list ap);
int							ft_printf(const char *str, ...);
#endif
