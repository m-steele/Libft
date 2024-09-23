/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:27:40 by ekosnick          #+#    #+#             */
/*   Updated: 2024/09/23 10:28:17 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Allows user to replace a number of bytes, relegated to ascii
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	while (n--)
		((unsigned char *)s)[n] = (unsigned char)c;
	return (s);
}
