/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:46:00 by peatjohnsto       #+#    #+#             */
/*   Updated: 2024/12/27 13:05:49 by ekosnick         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

// t_list	*ft_lstnew(void *ct)
// {
// 	t_list	*new_node;

// 	new_node = malloc(sizeof(t_list));
// 	if (!new_node)
// 		return (NULL);
// 	new_node->ct = ct ? ft_strdup(ct) : NULL;
// 	new_node->nt = NULL;
// 	return (new_node);
// }

t_list	*ft_lstnew(void *ct)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->ct = ct;
	new_node->nt = NULL;
	if (!new_node)
		return (NULL);
	return (new_node);
}
