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

/* Int-putchar is useless because write has a ret value */

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_base(long nb, int baselen, char *base, int *ret)
{
	if (nb < 0)
	{
		nb = -nb;
		*ret += write(1, "-", 1);
	}
	if (nb >= baselen)
		ft_putnbr_base(nb / baselen, baselen, base, ret);
	*ret += write(1, &base[nb % baselen], 1);
}

void	ft_putnbr_base_ptr(unsigned long nb, int baselen, char *base, int *ret)
{
	if (nb >= (unsigned long)baselen)
		ft_putnbr_base_ptr(nb / (unsigned long)baselen, baselen, base, ret);
	*ret += write(1, &base[nb % (unsigned long)baselen], 1);
}
