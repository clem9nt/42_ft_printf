#include "ft_printf.h"
// p 09 sucks
int	main(void)
{
	int ret;
	char *nul = NULL;
	/* int *ptr; */
	/* int	nb = 2; */

	/* ptr = &nb; */
	/* ft_printf("c:%c s:%s p:%p i:%i u:%u x:%x X:%X %%\n", */
	/* 		'c', "ss", ptr, -42, 42, 42, 42); */
	ret = ft_printf("%s s:%s c:%c %%\n", nul, "mine", 'c');
	printf("%i\n", ret);
	ret = printf("%s s:%s c:%c %%\n", nul, "orig", 'c');
	printf("%i\n", ret);
	return (0);
}
