

// replaces specified number of bytes with zero '\0'
// #include "libft.h"
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// #include <stdio.h>
// int main(void)
// {
// 	char d[] = "HUGE!";
// 	char dd [] = "HUGER!";
// 	ft_bzero(dd, 2);
// 	printf("%s\n", dd);
// 	bzero(d, 2);
// 	printf("%s\n", d);
// 	return (0);
// }