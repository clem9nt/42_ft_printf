/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:12:16 by cvidon            #+#    #+#             */
/*   Updated: 2021/12/07 16:17:08 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrbase(long n, int baselen, char *base, int *len)
{
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
		*len += 1;
	}
	if (n >= baselen)
		ft_putnbrbase((long)(n / baselen), baselen, base, len);
	*len += 1;
	write(1, &base[n % baselen], 1);
}

void	ft_putnbrbase_ptr(unsigned long n, int baselen, char *base, int *len)
{
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		*len += 1;
	}
	if (n >= (unsigned int)baselen)
		ft_putnbrbase_ptr(n / (unsigned long)(baselen), baselen, base, len);
	*len += 1;
	write(1, &base[n % (unsigned long)baselen], 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if (!s)
		return ;
	write(1, s, i);
}
