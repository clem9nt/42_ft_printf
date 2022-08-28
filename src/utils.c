/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:11:59 by cvidon            #+#    #+#             */
/*   Updated: 2022/01/28 18:42:40 by clem9nt          888   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 ** @brief      Output number.
 **
 ** @param[in]  nb a numeric value.
 ** @param[out] r the outputted characters count.
 */

void	ft_putnbr(int n, ssize_t *r)
{
	long	ln;

	ln = n;
	if (ln < 0)
	{
		ln = -ln;
		*r += write (1, "-", 1);
	}
	if (ln >= 10)
		ft_putnbr ((int)(ln / 10), r);
	*r += write (1, &"0123456789"[ln % 10], 1);
}

/*
 ** @brief      Output unsigned number in specified base.
 **
 ** Example:
 ** ft_putuns_base (42, 16, "0123456789abcdef", &r);
 ** >> 2a
 **
 ** @param[in]  nb a numeric value.
 ** @param[in]  baselen the length of the base (ie. 10).
 ** @param[in]  base the character set of the base (ie. 0123456789).
 ** @param[out] r the outputted characters count.
 */

void	ft_putuns_base(size_t nb, size_t baselen, char *base, ssize_t *r)
{
	if (nb >= baselen)
		ft_putuns_base (nb / baselen, baselen, base, r);
	*r += write(1, &base[nb % baselen], 1);
}
