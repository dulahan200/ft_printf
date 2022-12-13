#include "ft_printf.h"

int	main(void)
{
char *s = "";
int n = -5425;
char c = 'w';

int	r;
int	myr;

//	printf("%c \n %s \n %p \n %d \n %i \n %u \n %x \n %X \n %%")
//	ft_printf("test\n", c);
//	ft_printf("%%%%\n", c);
//r =	ft_printf("%s", "some string with %s hehe");
//myr =	ft_printf("%s", "some string with %s hehe");
//r = printf("%ss%ss%ss", "And ", "some other", "joined");
//printf("\n");
//myr = ft_printf("%ss%ss%ss", "And ", "some other", "joined");
myr = ft_printf("%d", n);
printf("\n"); 
printf("expected result	");
r = printf("%d", n );
printf("\n"); 
//	ft_printf("%s","");
//	ft_printf("%s",(char *)NULL);
//	ft_putstr_fd("test",1);
//	ft_printf("ab%%%%ab");
//	ft_printf("ab%%%%ab");
printf("printf		%d\nft_printf	%d\n", r, myr);

}
