/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:50:23 by ekosnick          #+#    #+#             */
/*   Updated: 2024/09/17 12:18:16 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// will check if the character is alpha
int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return(1);
	return(c);
}