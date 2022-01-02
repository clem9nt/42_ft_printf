#include "ft_printf.h"
#include <stdio.h>
// p 09 sucks
int	main(void)
{
	int *ptr;
	int	nb = 2;
	int	ret;

	ptr = &nb;
	ft_printf("salut\n");
	ft_printf("c:%c s:%s p:%p i:%i u:%u x:%x X:%X %%\n",
			'c', "ss", ptr, -42, -42, -42, -42);

	ret = ft_printf(" s:%s c:%c s:%s u:%u %%\n", "mine", 'c', "salut", -42);
	printf("%i\n", ret);
	ret = printf(" s:%s c:%c s:%s u:%u %%\n", "orig", 'c', "salut", -42);
	printf("%i\n", ret);


	return (0);
}
