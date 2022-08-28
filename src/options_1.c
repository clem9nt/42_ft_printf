/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:11:59 by cvidon            #+#    #+#             */
/*   Updated: 2022/01/28 18:42:34 by clem9nt          888   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 ** @brief		'%%'
 */

int	ft_pct(va_list args)
{
	(void)args;
	return ((int)write (1, "%", 1));
}

/*
 ** @brief		'%c'
 */

int	ft_chr(va_list args)
{
	char	c;

	c = (char) va_arg (args, int);
	return ((int)write (1, &c, 1));
}

/*
 ** @brief		'%s'
 */

int	ft_str(va_list args)
{
	char	*str;
	ssize_t	r;

	r = 0;
	str = va_arg (args, char *);
	if (!str)
		r = write (1, "(null)", 6);
	else
		while (str[r])
			r += write (1, &str[r], 1);
	return ((int)r);
}

/*
 ** @brief		'%i' and '%d'
 */

int	ft_nbr(va_list args)
{
	int	nb;
	ssize_t	r;

	r = 0;
	nb = va_arg (args, int);
	ft_putnbr (nb, &r);
	return ((int)r);
}
