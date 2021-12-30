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

static int	get_option(char c)
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

static void	set_options(int (*option[8])(va_list))
{
	option[0] = ft_chr;
	option[1] = ft_str;
	option[2] = ft_ptr;
	option[3] = ft_nbr;
	option[4] = ft_uni;
	option[5] = ft_hx1;
	option[6] = ft_hx2;
	option[7] = ft_pct;
}

static int parsing(int (*option[8])(va_list), const char *format, va_list args)
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
		ret += ((*option[get_option(*format++)])(args));
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		(*option[8])(va_list);
	va_list	args;
	int		ret;

	ret = 0;
	set_options(option);
	va_start(args, format);
	ret = parsing(option, format, args);
	va_end(args);
	return (ret);
}
