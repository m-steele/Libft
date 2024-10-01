/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:25:06 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/01 15:23:53 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// use a delimiter char to break a string into chuncks
// ft_find_nwords() to create 'n' to store the number of breaks (words) for
// ft_split(). ft_aryfree() to free memory. MAGIC: ft_write_word()
// will copy each word recursively... I hope it is permitted
#include "libft.h"

static int	ft_find_nwords(char const *s, char c, int n)
{
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

// Copy each word, recursively
static char **ft_write_words(char **words, char const *s, char c, int i)
{
	char	*catch;
	int 	len;
	
	len = 0;
	while (*s == c)
		s++;
	if (*s == '\0')
	{
		words[i] = NULL;
		return (words);
	}
	catch = (char *)s;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	words[i] = (char *)malloc((len + 1) * sizeof(char));
	if (!words[i])
		return (aryfree(words, i));
	ft_strlcpy(words[i], catch, len + 1);
	return (ft_write_words(words, s, c, i + 1));
}

char	**ft_split(char const *s, char c)
{
	char	**ary4ary;
	int		nwords;

	if (!s)
		return (NULL);
	nwords = ft_find_nwords(s, c, 0);
	ary4ary = (char **)malloc((nwords + 1) * sizeof(char *));
	if (!ary4ary)
		return (NULL);
	return (ft_write_words(ary4ary, s, c, 0));
}
