
#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	void	*point;

	point = (void*)malloc(nmemb * size);
	if (!point)
		return (NULL);
	ft_bzero(point, nmemb);
	return (point);
}