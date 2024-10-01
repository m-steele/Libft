/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:46:11 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/01 13:04:47 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sets all the allocated bytes to 0
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*point;
	if (!nmemb || !size)
		return(NULL);
	if (nmemb * size/size != nmemb)
		return(NULL);
	point = (void *)malloc(nmemb * size);
	if (!point)
		return (NULL);
	ft_bzero(point, nmemb);
	return (point);
}
