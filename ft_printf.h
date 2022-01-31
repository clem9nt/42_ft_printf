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

/* Prod */
# include <stdarg.h>
# include <unistd.h>

/* Dev */
# include <stdio.h>

/* utils.c */
size_t	ft_strlen(char *str);
void	ft_putnbr_base(long nb, int baselen, char *base, int *ret);
void	ft_putnbr_base_ptr(unsigned long nb, int baselen, char *base, int *ret);
/* options_1.c */
int		ft_pct(va_list args);
int		ft_chr(va_list args);
int		ft_str(va_list args);
int		ft_nbr(va_list args);
/* options_2.c */
int		ft_uns(va_list args);
int		ft_hx1(va_list args);
int		ft_hx2(va_list args);
int		ft_ptr(va_list args);
/* ft_printf.c */
int		ft_printf(const char *fmt, ...);

#endif
