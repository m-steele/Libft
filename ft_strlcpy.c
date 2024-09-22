
// ensures '\0' is in string copy. returns length of src

#include "libft.h"

size_t ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	src_len;
	
	src_len = ft_strlen(src);
	if (destsize == 0)
		return (src_len);
	if (src_len + 1 < destsize)
		ft_memcpy(dest, src, src_len + 1);
	else if (destsize != 0)
	{
		ft_memcpy(dest, src, destsize - 1);
		dest[destsize - 1] = 0;
	}
	return (src_len);
}
