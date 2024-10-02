/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:34:48 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/02 14:59:23 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// looking for litte string in big string; need two indexes
// NULL if no little; cpy big starting where it starts from little
// within a given range of bytes def by user
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*little)
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (big[i + j] == little[j] && i + j < len)
			if (!little[++j])
				return ((char *)big + i);
		i++;
	}
	return (NULL);
}
