/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:55:28 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/01 15:58:49 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Changes uppercase to lower
#include "libft.h"

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		return (c + 32);
	return (c);
}