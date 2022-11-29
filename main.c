#include "ft_printf.h"

int	main(void)
{
char *s = "patata";
int n = 200;
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
r = ft_printf("%a");
myr = printf("%a");

//	ft_printf("%s","");
//	ft_printf("%s",(char *)NULL);
//	ft_putstr_fd("test",1);
//	ft_printf("ab%%%%ab");
//	ft_printf("ab%%%%ab");
	printf("\nprintf = %d\nft_printf = %d", r, myr);

}
