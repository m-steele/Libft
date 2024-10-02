/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:46:11 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/02 10:29:08 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sets all the allocated bytes to 0
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*point;

	if (!nmemb || !size)
		return (NULL);
	if (nmemb * size / size != nmemb)
		return (NULL);
	point = (void *)malloc(nmemb * size);
	if (!point)
		return (NULL);
	ft_bzero(point, nmemb);
	return (point);
}
