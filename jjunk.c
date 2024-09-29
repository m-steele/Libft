/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jjunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:25:06 by ekosnick          #+#    #+#             */
/*   Updated: 2024/09/29 10:40:08 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// use a delimiter character to break a string into chuncks
// ft_find_nwords() to create 'n' to store the number of breaks (words) for
// ft_split(). ft_aryfree() to free memory. MAGIC: ft_write_word()
// will copy each word recursively... I hope it is permitted
#include "libft.h"
#include <stdio.h>
// Determine number of words 'n'
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

// Copy each word into an array
static char *ft_write_word(const char *s, char c, int i)
{
	char	*word;
	int 	len;
	
	len = 0;
	i = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**ary4ary;
	int		nwords;
	i 
	
	if (!s)
		return (NULL);
	nwords = ft_find_nwords(s, c, 0);
	ary4ary = (char **)malloc((nwords + 1) * sizeof(char *));
	if (!ary4ary)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			ary4ary[i] = ft_write_word(s, c, 0);
		}
	}
	return (0);
}


int main()
{
char splitter[]="___how_many______words_in_this_string?__";
 	char **words;
    int spliti = 0;
    words = ft_split(splitter, '_');
	// while (words[spliti] != NULL)
	// 	printf("%s\n", words[spliti]);
	// aryfree(words, spliti);
    for (spliti = 0; words[spliti] != NULL; spliti++)
    	printf("%s\n", words[spliti]);
    aryfree(words, spliti);
}