/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:41:17 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/19 11:34:06 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	type_ck(const char *str, va_list args)
{
	int		n;

	n = 0;
	if (*str == 's')
		n += process_s(args);
	else if (*str == 'i' || *str == 'd')
		n += process_id(args);
	else if (*str == 'c')
		n += process_c(args, *str);
	else if (*str == 'p')
		n += process_p(args);
	else if (*str == 'u')
		n += process_u(args);
	else if (*str == 'x')
		n += process_x(args);
	else if (*str == 'X')
		n += process_xx(args);
	else
		return (0);
	return (n);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		n;

	n = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			if (*str == '%')
				n += write(1, "%", 1);
			else
				n += type_ck(str, args);
		}
		else
			n += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (n);
}

// my original that works mostly well: with 29 lines
// int	ft_printf(const char *str, ...)
// {
// 	va_list	args;
// 	int		n;

// 	n = 0;
// 	if (!str)
// 		return (0);
// 	va_start(args, str);
// 	while (*str)
// 	{
// 		if (*str == '%')
// 		{
// 			str++;
// 			if (*str == '%')
// 			{
// 				write(1, "%", 1);
// 				n++;
// 			}
// 			else if (*str)
// 				n += type_ck(str, args);
// 		}
// 		else
// 		{
// 			write(1, str, 1);
// 			n++;
// 		}
// 		str++;
// 	}
// 	va_end(args);
// 	return (n);
// }