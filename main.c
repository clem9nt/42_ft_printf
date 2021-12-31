#include "ft_printf.h"
// p 09 sucks
int	main(void)
{
	int *ptr;
	int	nb = 2;

	ptr = &nb;
	ft_printf("salut\n");
	ft_printf("c:%c s:%s p:%p i:%i u:%u x:%x X:%X %%\n",
			'c', "ss", ptr, -42, 42, 42, 42);
	return (0);
}
