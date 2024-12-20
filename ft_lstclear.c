/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.f>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 08:50:34 by peatjohnsto       #+#    #+#             */
/*   Updated: 2024/12/20 12:29:14 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del || !*lst)
		return ;
	while (*lst && lst)
	{
		temp = (*lst)->nt;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}
