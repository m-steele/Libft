/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:27:40 by ekosnick          #+#    #+#             */
/*   Updated: 2024/09/19 13:27:58 by ekosnick         ###   ########.fr       */
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
// #include <stdio.h>
// int main()
// {
// 	char h[] ="Hello!";
// 	printf("%s\n", h);
// /*may need to  use the putstr or cpystr function
// to get the expected result.
// but then we would just use the replace fumction, so never mind
// 	unsigned char j [] ="jello?";*/
// 	ft_memset(h, 'j', 1);
// 	printf("%s\n", h);
// 	return (0);
// }