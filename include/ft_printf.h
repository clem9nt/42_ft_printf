/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clem9nt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:42:28 by clem9nt           #+#    #+#             */
/*   Updated: 2022/01/28 18:42:29 by clem9nt          888   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
 ** =========[ Includes ]==========
 */

# include <stdarg.h>
# include <unistd.h>

# include <stdio.h>

/*
 ** =========[ Prototypes ]========
 */

/*
 ** utils.c
 */

void	ft_putnbr(int n, ssize_t *r);
void	ft_putuns_base(size_t nb, size_t baselen, const char *base, ssize_t *r);

/*
 ** options_2.c
 */

int		ft_pct(va_list args);
int		ft_chr(va_list args);
int		ft_str(va_list args);
int		ft_nbr(va_list args);

/*
 ** options_1.c
 */

int		ft_uns(va_list args);
int		ft_hx1(va_list args);
int		ft_hx2(va_list args);
int		ft_ptr(va_list args);

/*
 ** ft_printf.c
 **
 ** Format and print data.
 */

/* int	ft_parse(const char *fmt, va_list args, int (*opts[8])(va_list)) */
int		ft_printf(const char *fmt, ...);

#endif
