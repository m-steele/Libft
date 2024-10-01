/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:32:42 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/01 12:58:33 by peatjohnsto      ###   ########.fr       */
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
		if (nptr[i] == '-')
			sign = -1;
		else
			sign = 1;
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
