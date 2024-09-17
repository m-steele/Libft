

// Allows user to replace a number of bytes, relagated to ascii
// #include "libft.h"
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	while (n--)
		((unsigned char *)s)[n] = (unsigned char)c;
	return(s);
}
// #include <stdio.h>
// int main()
// {
// 	char h[] ="Hello!";
// 	printf("%s\n", h);
// /*may need to  use the putstr or cpystr function
// to get the expected result.
// but then we would just use the replace fumction, so never mind
// 	unsigned char j [] ="jello?";*/
// 	ft_memset(h, 'j', 1);
// 	printf("%s\n", h);
// 	return(0);
// }