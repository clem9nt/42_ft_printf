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
 * Read and parse the input
 */

static int	ft_read(int (*opt[8])(va_list), const char *fmt, va_list args)
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
			r += opt[id](args);
		}
		fmt++;
	}
	return (r);
}

/*
 * Initialize the supported flags
 */

int	ft_printf(const char *fmt, ...)
{
	int		(*opt[8])(va_list);
	va_list	args;
	int		r;

	opt[0] = ft_pct;
	opt[1] = ft_chr;
	opt[2] = ft_str;
	opt[3] = ft_nbr;
	opt[4] = ft_uns;
	opt[5] = ft_hx1;
	opt[6] = ft_hx2;
	opt[7] = ft_ptr;
	va_start (args, fmt);
	r = ft_read (opt, fmt, args);
	va_end (args);
	return (r);
}
