/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:11:59 by cvidon            #+#    #+#             */
/*   Updated: 2022/01/28 18:42:13 by clem9nt          888   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 ** @brief		Distribute arguments to proper functions.
 **
 ** @param[in]  fmt the list of flags indicating the type of each argument.
 ** @param[in]  args the list of arguments to print.
 ** @param[in]  (*opts[8])(va_list) an array of function pointers.
 ** @return     The number of characters that passed through stdout.
 **
 */

static int	ft_parse(const char *fmt, va_list args, int (*opts[8])(va_list))
{
	int	r;
	int	id;

	r = 0;
	while (*fmt)
	{
		if (*fmt != '%')
			r += (int) write (1, fmt, 1);
		else if (*(fmt + 1))
		{
			fmt++;
			id = 0 * (*fmt == '%')
				+ 1 * (*fmt == 'c')
				+ 2 * (*fmt == 's')
				+ 3 * (*fmt == 'i' || *fmt == 'd')
				+ 4 * (*fmt == 'u')
				+ 5 * (*fmt == 'x')
				+ 6 * (*fmt == 'X')
				+ 7 * (*fmt == 'p')
				;
			r += opts[id](args);
		}
		fmt++;
	}
	return (r);
}

/*
 ** @brief      Initialize array of options.
 **
 ** @param[in]  (*opts[8])(va_list) an array of function pointers.
 */

static void	ft_init(int (*opts[8])(va_list))
{
	opts[0] = ft_pct;
	opts[1] = ft_chr;
	opts[2] = ft_str;
	opts[3] = ft_nbr;
	opts[4] = ft_uns;
	opts[5] = ft_hx1;
	opts[6] = ft_hx2;
	opts[7] = ft_ptr;
}
/*
 ** @brief      Format and print data.
 **
 ** "The  functions in the printf() family produce output according to a format
 ** as described below. The functions printf() write output to stdout."
 **
 ** @see        PRINTF(3) <stdio.h>
 */

int	ft_printf(const char *fmt, ...)
{
	int		(*opts[8])(va_list);
	va_list	args;
	int		r;

	ft_init (opts);
	va_start (args, fmt);
	r = ft_parse (fmt, args, opts);
	va_end (args);
	return (r);
}
