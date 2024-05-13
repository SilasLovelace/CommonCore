#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{	
	char c;
	int	ret1;
	int	ret2;

	c = 'k';
	ret1 = printf("Start with a char: %c\n", c);
	ret2 = ft_printf("Start with a char: %c\n", c);
	printf("ret printf:    %d\n", ret1);
	printf("ret ft_printf: %d\n", ret2);

	ret1 = printf("Start with a char: %c %c %c \n", 'a', 'b', 'c');
	ret2 = ft_printf("Start with a char: %c %c %c \n", 'a', 'b', 'c');
	printf("ret printf:    %d\n", ret1);
	printf("ret ft_printf: %d\n", ret2);

	ret1 = printf("Now a string: %s %s %s \n", "Hello", "Hi", "Hola");
	ret2 = ft_printf("Now a string: %s %s %s \n", "Hello", "Hi", "Hola");
	printf("ret printf:    %d\n", ret1);
	printf("ret ft_printf: %d\n", ret2);

	ret1 = printf("Now the string NULL: %s \n", (char*)NULL);
	ret2 = ft_printf("Now the string NULL: %s \n", (char*)NULL);
	printf("ret printf:    %d\n", ret1);
	printf("ret ft_printf: %d\n", ret2);

	ret1 = printf("Number: %i %d %d %d \n", 42, -1234, INT_MAX, INT_MIN);
 	ret2 = ft_printf("Number: %i %d %d %d \n", 42, -1234, INT_MAX, INT_MIN);
	printf("ret printf:    %d\n", ret1);
	printf("ret ft_printf: %d\n", ret2);

	ret1 = printf("Now a number: %d \n", -1234);
 	ret2 = ft_printf("Now a number: %d \n", -1234);
	printf("ret printf:    %d\n", ret1);
	printf("ret ft_printf: %d\n", ret2);

	ret1 = printf("Number as hexa: %x %x %x\n", 42, -1234, INT_MAX);
	ret2 = ft_printf("Number as hexa: %x %x %x\n", 42, -1234, INT_MAX);
	printf("ret printf:    %d\n", ret1);
	printf("ret ft_printf: %d\n", ret2);

	ret1 = printf("Number as hexa: %X %X %X\n", 42, -1234, INT_MAX);
	ret2 = ft_printf("Number as hexa: %X %X %X\n", 42, -1234, INT_MAX);
	printf("ret printf:    %d\n", ret1);
	printf("ret ft_printf: %d\n", ret2);

	ret1 = printf("Number as unsigned: %u %u %u %u\n", 42, -1234, UINT_MAX, (unsigned int)-1);
	ret2 = ft_printf("Number as unsigned: %u %u %u %u\n", 42, -1234, UINT_MAX, (unsigned int)-1);
	printf("ret printf:    %d\n", ret1);
	printf("ret ft_printf: %d\n", ret2);

	char *string1 = NULL;
	
	printf("Check for NULL ptr and string\n\n");
	ret1 = printf("Addresses: %p\n %p\n %s\n", &c, string1, string1);
	ret2 = ft_printf("Addresses: %p\n %p\n %s\n", &c, string1, string1);
	printf("ret printf:    %d\n", ret1);
	printf("ret ft_printf: %d\n", ret2);


	ret1 = printf(NULL);
	ret2 = ft_printf(NULL);
	printf("ret printf:    %d\n", ret1);
	printf("ret ft_printf: %d\n", ret2);

	printf("\nEnd of check\n");

	ret1 = printf("Print percent sign: %%\n");
	ret2 = ft_printf("Print percent sign: %%\n");
	printf("ret printf:    %d\n", ret1);
	printf("ret ft_printf: %d\n", ret2);
	
	printf("ret printf:    %d\n", printf("%%%"));
	printf("ret ft_printf: %d\n", ft_printf("%%%"));

	// if I printf a lone % sign without format specifier after:
	// will create undefined behavior
	// can compile and test it with:
	// cc main_test_ft_printf.c -Wmp-format -L. -lftprintf 
// 	ret1 = printf("put a single percent sign without format specifier? %\n");
//	ret2 = ft_printf("put a single percent sign without format specifier? %\n");
//	printf("ret printf:    %d\n", ret1);
//	printf("ret ft_printf: %d\n", ret2);

/*
	close(STDOUT_FILENO);  // Close standard output
	//if (printf("This will fail to print\n") == -1) {
    //	perror("Failed to print");
	//}
	ret1 = printf("This will fail\n");
	ret2 = ft_printf("This will fail to print\n");
//	open(STDOUT_FILENO);
//	printf("ret printf:    %d\n", ret1);
//	printf("ret ft_printf: %d\n", ret2);
    ret1 = printf("This will fail\n"); 
    ret2 = printf("This will fail to print\n"); 

    fprintf(stderr, "ret printf:    %d\n", ret1);
    fprintf(stderr, "ret ft_printf: %d\n", ret2);
*/
	return (0);
}
