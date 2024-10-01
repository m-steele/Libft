/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:49:33 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/01 15:29:43 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// appends scr to end of dest ensuring '\0' return length of new string
// will be the smaller of (dst || dstsize) plus the source
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ret;

	i = 0;
	while (*dst && i < dstsize)
	{
		++dst;
		++i;
	}
	ret = ft_strlcpy(dst, src, dstsize -1);
	return (ret + i);
}
