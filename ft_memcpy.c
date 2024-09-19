/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:29:52 by ekosnick          #+#    #+#             */
/*   Updated: 2024/09/19 13:31:04 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Copy memory from src to dest. There are not overlaps.
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	tmp_dest = (unsigned char *) dest;
	tmp_src = (unsigned char *) src;
	while (n--)
		*tmp_dest++ = *tmp_src++;
	return (dest);
}
