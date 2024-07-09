/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:54:13 by dsiroten          #+#    #+#             */
/*   Updated: 2024/04/02 14:54:14 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;
	t_list	*n;

	if (!lst || !del)
		return ;
	p = *lst;
	while (p)
	{
		n = p->next;
		ft_lstdelone(p, del);
		p = n;
	}
	*lst = 0;
}
