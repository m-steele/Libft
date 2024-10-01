/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:55:44 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/01 15:59:28 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Changes lowercase to uppercase
#include "libft.h"

int ft_toupper(int c)
{
	if (c > 96 && c < 123)
		return (c - 32);
	return (c);
}
