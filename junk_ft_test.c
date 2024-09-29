#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

// Determine number of words
// static int	ft_find_nwords(char const *s, char c, int n)
// {
// 	while (*s)
// 	{
// 		if (*s == c)
// 			s++;
// 		else
// 		{
// 			n += 1;
// 			while (*s && *s != c)
// 				s++;
// 		}
// 	}
// 	return (n);
// }
// // Function to free the memory
// static char **aryfree(char **ptr, int i)
// {
//     while (i > 0)
//     {
//         i--;
//         free(ptr[i]);
//     }
//     free(ptr);
//     return (NULL);
// }

// // Recursive function to split the string
// static char **ft_write_recurs(char **result, char const *s, char c, int i)
// {
//     char *start;
//     int len;

//     // Skip leading delimiters
//     while (*s == c)
//         s++;
//     if (*s == '\0')
//     {
//         result[i] = NULL;
//         return (result);
//     }
//     // Find the length of the next word
//     start = (char *)s;
//     len = 0;
//     while (*s != c && *s != '\0')
//     {
//         len++;
//         s++;
//     }
//     // Allocate memory for the word and copy it
//     result[i] = (char *)malloc(len + 1);
//     if (!result[i])
//         return (aryfree(result, i));
//     ft_strlcpy(result[i], start, len + 1);
//     // Recur for the next word
//     return (ft_write_recurs(result, s, c, i + 1));
// }

// // Main split function
// char **ft_split(char const *s, char c)
// {
//     char **result;
//     int nwords;

//     if (!s)
//         return (NULL);
//     nwords = ft_find_nwords(s, c, 0);
//     result = (char **)malloc((nwords + 1) * sizeof(char *));
//     if (!result)
//         return (NULL);
//     return (ft_write_recurs(result, s, c, 0));
// }

#include <stdlib.h>
#include <string.h>

// Determine number of words 'n'
static int ft_find_nwords(char const *s, char c)
{
    int n = 0;
    int in_word = 0;

    while (*s)
    {
        if (*s != c && !in_word)
        {
            n++;
            in_word = 1;
        }
        else if (*s == c)
            in_word = 0;
        s++;
    }
    return (n);
}

// Free memory in case of failure
static char **aryfree(char **ptr, int i)
{
    while (i > 0)
    {
        i--;
        free(ptr[i]);
    }
    free(ptr);
    return (0);
}

// Copy each word into the array
static char **ft_write_words(char **words, char const *s, char c)
{
    int i = 0;
    int len;
    char *start;

    while (*s)
    {
        while (*s == c)
            s++; // Skip delimiters
        if (*s == '\0')
            break; // End of string
        start = (char *)s;
        len = 0;
        while (*s && *s != c)
        {
            len++;
            s++;
        }
        words[i] = (char *)malloc((len + 1) * sizeof(char));
        if (!words[i])
            return (aryfree(words, i));
        strncpy(words[i], start, len);
        words[i][len] = '\0';
        i++;
    }
    words[i] = NULL; // Null-terminate the array
    return (words);
}

char **ft_split(char const *s, char c)
{
    char **ary4ary;
    int nwords;

    if (!s)
        return (NULL);
    nwords = ft_find_nwords(s, c);
    ary4ary = (char **)malloc((nwords + 1) * sizeof(char *));
    if (!ary4ary)
        return (NULL);
    return (ft_write_words(ary4ary, s, c));
}


int main()
{
char splitter[]="___how_many______words_in_this_string?__";
 	char **words;
    int spliti;
    words = ft_split(splitter, '_');
   for (spliti = 0; words[spliti] != NULL; spliti++)
    	printf("%s\n", words[spliti]);
    aryfree(words, spliti);
}