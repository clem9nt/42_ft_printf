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
#include <limits.h>
#include <stdio.h>

#define RET fprintf(stdout, " > %i\n", ret)

/*
 ** @brief		ft_printf tester.
 */

int	main(void)
{
	int     ret;
	char    *null;
	null = NULL;
	fprintf(stdout, "Printf testing...\n");
	ft_printf ("%");
	ft_printf ("", "");
	fprintf(stdout, "\n  ---PCT---\n\n");
	ret = ft_printf ("%% %%%%"); RET;
	ret = fprintf(stdout, "%% %%%%"); RET;
	fprintf(stdout, "\n  ---CHR---\n\n");
	ret = ft_printf ("%c %c %c %c %c %c", 'X', 0, 42, -42, INT_MIN, INT_MAX); RET;
	ret = fprintf(stdout, "%c %c %c %c %c %c", 'X', 0, 42, -42, INT_MIN, INT_MAX); RET;
	fprintf(stdout, "\n  ---STR---\n\n");
	ret = ft_printf ("%s %s %s", "string", "", null); RET;
	ret = fprintf(stdout, "%s %s %s", "string", "", null); RET;
	fprintf(stdout, "\n  ---NBR---\n\n");
	ret = ft_printf ("%i %i %i %i %i %i", 'X', 0, 42, -42, INT_MIN, INT_MAX); RET;
	ret = fprintf(stdout, "%i %i %i %i %i %i", 'X', 0, 42, -42, INT_MIN, INT_MAX); RET;
	fprintf(stdout, "\n  ---UNS---\n\n");
	ret = ft_printf ("%u %u %u %u %u %u", 'X', 0, 42, -42, INT_MIN, INT_MAX); RET;
	ret = fprintf(stdout, "%u %u %u %u %u %u", 'X', 0, 42, -42, INT_MIN, INT_MAX); RET;
	fprintf(stdout, "\n  ---HX1---\n\n");
	ret = ft_printf ("%x %x %x %x %x %x", 'X', 0, 42, -42, INT_MIN, INT_MAX); RET;
	ret = fprintf(stdout, "%x %x %x %x %x %x", 'X', 0, 42, -42, INT_MIN, INT_MAX); RET;
	fprintf(stdout, "\n  ---HX2---\n\n");
	ret = ft_printf ("%X %X %X %X %X %X", 'X', 0, 42, -42, INT_MIN, INT_MAX); RET;
	ret = fprintf(stdout, "%X %X %X %X %X %X", 'X', 0, 42, -42, INT_MIN, INT_MAX); RET;
	fprintf(stdout, "\n  ---HX2---\n\n");
	ret = ft_printf ("%X %X %X %X %X %X", 'X', 0, 42, -42, INT_MIN, INT_MAX); RET;
	ret = fprintf(stdout, "%X %X %X %X %X %X", 'X', 0, 42, -42, INT_MIN, INT_MAX); RET;
	fprintf(stdout, "\n  ---PTR---\n\n");
	ret = ft_printf ("%p %p %p", (void *)null, (void *)&ret, NULL); RET;
	ret = fprintf(stdout, "%p %p", (void *)null, (void *)&ret); RET;
	fprintf(stdout, "\n  ---MIX---\n\n");
	ret = ft_printf ("- %% %c %s %i %u %x %X %x %p ", 97, "b", 0, -1, -2, -3, -4, (void *)null); RET;
	ret = fprintf(stdout, "- %% %c %s %i %u %x %X %x %p ", 97, "b", 0, -1, -2, -3, -4, (void *)null); RET;

	return (0);
}

