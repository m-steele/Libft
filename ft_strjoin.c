
// trying to condense the code as much as possible :p
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int	i;
	int	ii;
	int	j;
	char	*join;
	
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		join[j++] = s1[i++];
	ii = 0;
	while (s2[ii])
		join[j++] = s2[ii++];
	join[j] = '\0';
	return (join);
}

// NOte the below works inplace of the while loops
	// ft_strlcpy(join, s1, len); 
	// ft_strlcat(join, s2, len);
