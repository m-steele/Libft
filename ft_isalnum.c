/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:36:17 by ekosnick          #+#    #+#             */
/*   Updated: 2024/09/17 12:39:59 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// checks if character is number or letter
int	ft_isalnum(int c)
{
	if (ft_isalpha(c)) || ft(_isdigit(c))
		return(1);
	return(0);
}