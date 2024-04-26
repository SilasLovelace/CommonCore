#include <limits.h>
#include <stdio.h>
#include "libftprintf.h"

int main ()
{
	char* t = "hello";
	int i = INT_MIN;
	unsigned int u = UINT_MAX;
	ft_printf("%d\n", 	ft_printf	("ft %s %c %i %d %x %X %p %u %%\n", t, t[0], i, i, 123123, 123123, t, u));
	printf("%d\n",		printf		("pf %s %c %i %d %x %X %p %u %%\n", t, t[0], i, i, 123123, 123123, t, u));
    ft_printf("NULLCHECKS\n");
    ft_printf("%d\n", 	ft_printf	("ft %s %c %i %d %x %X %p %%\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
	printf("%d\n",		printf		("pf %s %c %i %d %x %X %p %%\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
	return (0);
}