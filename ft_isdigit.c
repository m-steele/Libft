/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:23:24 by ekosnick          #+#    #+#             */
/*   Updated: 2024/09/17 12:26:26 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this checks if the character is a number
int 	ft_isdigit(signed int c)
{
	if (c > 47 && c < 58)
		return(1);
	return(c);
}