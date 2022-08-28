/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:11:59 by cvidon            #+#    #+#             */
/*   Updated: 2022/01/28 18:42:37 by clem9nt          888   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 ** @brief		'%u'
 */

int	ft_uns(va_list args)
{
	unsigned int	nb;
	ssize_t			r;

	r = 0;
	nb = va_arg (args, unsigned int);
	ft_putuns_base (nb, 10, "0123456789", &r);
	return ((int)r);
}

/*
 ** @brief		'%x'
 */

int	ft_hx1(va_list args)
{
	unsigned int	nb;
	ssize_t			r;

	r = 0;
	nb = va_arg (args, unsigned int);
	ft_putuns_base (nb, 16, "0123456789abcdef", &r);
	return ((int)r);
}

/*
 ** @brief		'%X'
 */

int	ft_hx2(va_list args)
{
	unsigned int	nb;
	ssize_t			r;

	r = 0;
	nb = va_arg (args, unsigned int);
	ft_putuns_base (nb, 16, "0123456789ABCDEF", &r);
	return ((int)r);
}

/*
 ** @brief		'%p'
 */

int	ft_ptr(va_list args)
{
	unsigned long	nb;
	ssize_t			r;

	nb = va_arg (args, unsigned long);
	if (!nb)
		return ((int)write (1, "(nil)", 5));
	r = (int)write (1, "0x", 2);
	ft_putuns_base (nb, 16, "0123456789abcdef", &r);
	return ((int)r);
}
