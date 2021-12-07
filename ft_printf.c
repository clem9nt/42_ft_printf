/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:11:59 by cvidon            #+#    #+#             */
/*   Updated: 2021/12/07 16:19:16 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_options_id(char c)
{
	int	id;

	id = 0 * (c == 'c')
		+ 1 * (c == 's')
		+ 2 * (c == 'p')
		+ 3 * (c == 'i' || c == 'd')
		+ 4 * (c == 'u')
		+ 5 * (c == 'x')
		+ 6 * (c == 'X')
		+ 7 * (c == '%');
	return (id);
}

static void	ft_options(int (*option[8])(void *))
{
	option[0] = (void *)ft_chr;
	option[1] = (void *)ft_str;
	option[2] = (void *)ft_ptr;
	option[3] = (void *)ft_nbr;
	option[4] = (void *)ft_uni;
	option[5] = (void *)ft_hx1;
	option[6] = (void *)ft_hx2;
	option[7] = (void *)ft_pct;
}

static int
	ft_parsing(int (*option[8])(void *), const char *format, va_list args)
{
	int	ret;

	ret = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			ret++;
			format++;
			continue ;
		}
		format++;
		ret += ((*option[ft_options_id(*format++)])(args));
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		(*option[8])(void *);
	va_list	args;
	int		ret;

	ret = 0;
	ft_options(option);
	va_start(args, format);
	ret = ft_parsing(option, format, args);
	va_end(args);
	return (ret);
}
