#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char str = '1';
	printf("%d\n", ft_isascii(str));
	printf("%d\n", isascii(str));
	return (0);
}