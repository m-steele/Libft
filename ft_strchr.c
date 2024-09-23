/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:24:09 by ekosnick          #+#    #+#             */
/*   Updated: 2024/09/23 10:26:57 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// return string from first occur of defined char or null
#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	while (*s)
	{
			if (*s == (char)c)
				return (char *)s;
			s++;
	}
	if (c == '\0')
		return (char *)s;
	return (NULL);
}
