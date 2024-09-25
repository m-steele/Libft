/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:32:42 by ekosnick          #+#    #+#             */
/*   Updated: 2024/09/25 09:46:31 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this is the atoi as it is in the man not piscine
#include "libft.h"

int ft_atoi(const char *nptr)
{
	int	i;
	int sign;
	int counter;
	
	i = 0;
	counter = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
			i++;
		sign = (nptr[i] == '-') ? -1 : 1;
		if (sign == -1 || nptr[i] == '+')
			i++;
		else if (nptr[i] == '+')
			i++;
		while (nptr[i] >= 48 && nptr[i] <= 57)
		{
			counter = (counter * 10) + (nptr[i] - '0');
			i++;
		}
	return (sign * counter);
}
