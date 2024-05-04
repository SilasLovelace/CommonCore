#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

int main ()
{
	char* eins = "eins";
	// printf("%d\n", 		printf		("%s", eins));
	// ft_printf("%d\n", 	ft_printf	("%s", eins));
	// printf("%d\n", 		printf		("%c ", eins[0]));
	// ft_printf("%d\n", 	ft_printf	("%c ", eins[0]));
	// printf("%d\n", 		printf		("%i ", INT32_MAX));
	// ft_printf("%d\n", 	ft_printf	("%i ", INT32_MAX));
	// printf("%d\n", 		printf		("%d ", INT32_MAX));
	// ft_printf("%d\n", 	ft_printf	("%d ", INT32_MAX));
	// printf("%d\n", 		printf		("%d ", INT32_MIN));
	// ft_printf("%d\n", 	ft_printf	("%d ", INT32_MIN));
	// printf("%d\n", 		printf		("%x ", INT32_MAX));
	// ft_printf("%d\n", 	ft_printf	("%x ", INT32_MAX));
	// printf("%d\n",	 	printf		("%X ", INT32_MAX));
	// ft_printf("%d\n", 	ft_printf	("%X ", INT32_MAX));
	// printf("%d\n",	 	printf		("%X ", INT32_MIN));
	// ft_printf("%d\n", 	ft_printf	("%X ", INT32_MIN));
	// printf("%d\n",	 	printf		("%p ", INT32_MIN));
	// ft_printf("%d\n", 	ft_printf	("%p ", INT32_MIN));
	// printf("%d\n",	 	printf		("%u ", UINT32_MAX));
	// ft_printf("%d\n", 	ft_printf	("%u ", UINT32_MAX));

	// printf("%d\n",	 	printf		(" %c %c %c ", '0', 0, '1'));
	// ft_printf("%d\n", 	ft_printf	(" %c %c %c ", '0', 0, '1'));
	ft_printf("ft%c\n", 0);
	printf("pf%c\n", 0);
	// printf("%d\n",	 	printf		(NULL));
	// ft_printf("%d\n", 	ft_printf	(NULL));
	// // printf("%d\n",	 	printf		("%"));
	// // ft_printf("%d\n", 	ft_printf	("%"));

	// char* t = "hello";
	// int i = INT_MIN;
	// unsigned int u = UINT_MAX;
	// ft_printf("COMBO\n");
	// ft_printf("%d\n", 	ft_printf	("ft %s %c %i %d %x %X %p %u %%\n", t, t[0], i, i, 123123, 123123, t, u));
	// printf("%d\n",		printf		("pf %s %c %i %d %x %X %p %u %%\n", t, t[0], i, i, 123123, 123123, t, u));
    // ft_printf("NULLCHECKS\n");
    // ft_printf("%d\n", 	ft_printf	("ft %s %c %i %d %x %X %p %%\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
	// printf("%d\n",		printf		("pf %s %c %i %d %x %X %p %%\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
	// ft_printf("NULLCHECKS\n");
    // ft_printf("%d\n", 	ft_printf	("ft %s %c %i %d %x %X %p %%\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
	// printf("%d\n",		printf		("pf %s %c %i %d %x %X %p %%\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
	
	return (0);
}
