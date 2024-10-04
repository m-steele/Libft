/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:46:11 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/03 18:33:45 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sets all the allocated bytes to 0
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*pnt;
	size_t			i;
	
	i = 0;
	pnt = (void *)malloc(nmemb * size);
	if (!pnt)
		return (NULL);
	while (i < nmemb * size)
		pnt[i++] = 0;
	return (pnt);
}
