/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:24:09 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/03 18:22:31 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// return string from first occur of defined char or null
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
		if (*s == (char)c)
			return ((char *)s);
	return (NULL);
}
