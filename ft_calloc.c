/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:46:11 by ekosnick          #+#    #+#             */
/*   Updated: 2024/09/25 14:49:03 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*point;
	if (!nmemb || !size)
		return(NULL);
	if (nmemb * size/size != nmemb)
		return(NULL);
	point = (void *)malloc(nmemb * size);
	if (!point)
		return (NULL);
	ft_bzero(point, nmemb);
	return (point);
}

// #include <stdio.h>    // For printf
// #include <string.h>   // For memcmp and memset
// #include "libft.h"    // Include your libft header for ft_calloc

// int main(void)
// {
//     size_t nmemb = -10;
//     size_t size = sizeof(int); /*sizeof(int)*/
//     int *arr;
// 	int *ar;
//     // Use ft_calloc to allocate memory for an array of 10 integers
//     arr = (int *)ft_calloc(nmemb, size);
//     // Check if memory allocation failed
//     if (!arr)
//     {
//         printf("Your memory allocation failed!\n");
// 	}	
// 	ar = (int *)calloc(nmemb, size);
// 	if (!ar)
// 	{
// 		printf("Delv memory allocation failed!\n");
// 	}
//     // Check if the allocated memory is properly zeroed
//     int all_zero = 1;
// 	int all_zero_s = all_zero;
// 	size_t i = 0;
// 	while  (i < nmemb)
//     {
//         if (arr[i] != 0)
//         {
//             all_zero = 0;
//             break;
//         }
// 		i++;
//     }
// 	if (all_zero)
//         printf("Yours passed: memory is properly zeroed.\n");
//     else
//         printf("Your test is'a no good!\n");
// 	free(arr);
//     // Free the allocated memory
// 	size_t	ii = 0;
// 	while (ii < nmemb)
// 	{
// 		if (ar[ii] !=0)
// 		{
// 			all_zero_s = 0;
// 			break;
// 		}
// 		ii++;
// 	}
// 	if (all_zero_s)
// 		printf("Devls passed: memory is properly zeroed.\n");
// 	else 
// 		printf("Devl test is'a no good!\n");
// 	free(ar);
// 	return (0);
// }
