/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:34:48 by ekosnick          #+#    #+#             */
/*   Updated: 2024/09/23 14:29:27 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	
	
	while (i > len)
	{
		if (little == "")
			return (*big);
		if (little[i] != big[i])
			i++;
		return (*little);
	}
	return(NULL);
}

#include <stdio.h>
#include <string.h>
int main()
{
	printf("\033[1;31mft_strnchr()\033[0m\n");
	const char big[] = "abcdefgabcdefgabcdefg";
	const char little[] = "abcdefgabcdefg";
	const char nothing[] = "";
	printf("Your 'a': %d\n", ft_strnstr(*big, *little, 5));
	printf("Devl 'a': %d\n", strnstr(*big, *little, 5));
	printf("Your 'g': %d\n", ft_strnstr(*big, *little, 20));
	printf("Devl 'g': %d\n", strnstr(*big, *little, 20));
	printf("Your 'null term': %d\n", ft_strnstr(*big, nothing, 5));
	printf("Devl 'null term': %d\n\n", strnstr(*big, nothing, 5));
return (0);
}