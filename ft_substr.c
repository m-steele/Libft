
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char 	*sub_s;
	size_t	i;

	if (!s)
		return(NULL);
	if (start >= ft_strlen(s))
		return(NULL);
	sub_s = (char *)malloc((len + 1) * sizeof(char));
	if (!sub_s)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i]= '\0';
	return (sub_s);
}
