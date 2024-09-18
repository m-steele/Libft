
// Copy memory from src to dest. There are not overlaps.
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (dest == NULL && src == NULL)
		return (NULL);

	unsigned char *tmp_dest;
	unsigned char *tmp_src;

	tmp_dest = (unsigned char *) dest;
	tmp_src = (unsigned char *) src;
	while (n--)
		*tmp_dest++ = *tmp_src++;
	return (dest);
}