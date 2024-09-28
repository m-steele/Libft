/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:53:26 by ekosnick          #+#    #+#             */
/*   Updated: 2024/09/27 15:03:29 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Trim the front and back of a string based on set characters
// use the ft_trim_set() to help identify the set while looping
// identify the number of chars to remove wth start
#include "libft.h"

static int	ft_trim_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_trim_set(s1[start], set))
		start++;
	end = (ft_strlen(s1));
	while (end > start && ft_trim_set(s1[end - 1], set))
		end--;
	trimmed = ft_substr(s1, start, end - start);
	if (!trimmed)
		return (NULL);
	return (trimmed);
}

/*
use substr starting at front half with length of the
remaining string end - start
*/