
#include "libft.h"

// appends scr to end of dest ensuring '\0' return length of new string
// but will be truncated if dstsize is too small, it will be the source
// plus the turncated dstsize

// size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
// {
// 	size_t src_len;
// 	size_t dst_len;
// 	size_t space_left;

// 	src_len = ft_strlen(src);
// 	dst_len = ft_strlen(dst);
// 	space_left = dstsize - dst_len -1;

// 	if (dst_len >= dstsize)
// 		return (dstsize + src_len);
// 	if (space_left > 0)
// 	{
// 		size_t cpy_len = (src_len < space_left) ? src_len : space_left;
// 		ft_memcpy(dst + dst_len, src, cpy_len);
// 		dst[dst_len + cpy_len] = 0;
// 	}
// 	return (dst_len + src_len);
// }

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t ret;

	i = 0;
	while (*dst && i < dstsize)
	{
		++dst;
		++i;
	}
	ret = ft_strlcpy(dst, src, dstsize -1);
	return (ret + i);
}
