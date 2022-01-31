/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:11:59 by cvidon            #+#    #+#             */
/*   Updated: 2022/01/28 18:42:32 by clem9nt          888   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Test
 */

int	main(void)
{
	int		ret0;
	int		ret1;
	char	*s;
	char	*null;

	s = "s";
	null = NULL;
	ret0 = 0;
	ret1 = 0;
	ret0 = ft_printf("salut %% %c %s %s %i %u %x %p\n",
			'c', s, null, 42, -42, -42, s);
	ret1 = printf("salut %% %c %s %s %i %u %x %p\n",
			'c', s, null, 42, -42, -42, s);
	printf("%i == %i", ret0, ret1);
	return (0);
}
