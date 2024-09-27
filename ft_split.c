/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:25:06 by ekosnick          #+#    #+#             */
/*   Updated: 2024/09/27 17:18:29 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// use a delimiter character to break a string into chuncks
// will need to create N to store the number of breaks (words) for
// **ft_split() then will have reference to other arrays.
#include "libft.h"

// Determine number of words
static int	ft_find_nwords(char const *s, char c)
{
	int		n;
		
	n = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			n += 1;
			while (*s && *s != c)
				s++;
		}
	}
	return (n);
}

// to free the memory
static char	**aryfree(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return(0);
}

// allocate the memory for the array needed to store the arrays
char	**ft_split(char const *s, char c)
{
	char	ary4ary;
	int		aryn;

	aryn = ft_find_nwords(s, c);
	ary4ary = (char *)malloc(aryn + 1);
	free(ary4ary);

}


// char	**ft_split(char const *s, char c)
// {

	
// }


// This function is for the counting the number of words
// #include <stdio.h>
// int main()
// {
// 	char string[]="__how_many______words_in_this_string?_";
// 	printf("%d", ft_find_nwords(string, '_'));
// return(0);
// }
