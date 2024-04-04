#include "libft.h"
#include <stdio.h>
#include <limits.h>

int main ()
{
	printf("ATOI\n");
	printf(ft_atoi("123") == atoi("123")? "yes\n":"no\n");
	printf(ft_atoi("-123") == atoi("-123")? "yes\n":"no\n");
	printf(ft_atoi("---123") == atoi("---123")? "yes\n":"no\n");
	printf(ft_atoi("-123asd") == atoi("-123avwqer")? "yes\n":"no\n");
	printf(ft_atoi("123123123123") == atoi("123123123123")? "yes\n":"no\n");
	printf(ft_atoi("") == atoi("")? "yes\n":"no\n");
	printf(ft_atoi("0") == atoi("0")? "yes\n":"no\n");
	
	printf("BZERO\n");
	char str1[10] = "Hello";
	char str2[10] = "Hello";
	ft_bzero(str1, sizeof(str1)); // Call your ft_bzero function
	bzero(str2, sizeof(str2));    // Call the standard bzero function
	printf(memcmp(str1, str2, sizeof(str1)) == 0 ? "yes\n" : "no\n");
}
