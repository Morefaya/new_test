/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:28:11 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/06 16:28:13 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_addr(t_list **lst, t_list *link, void (*del)(void*, size_t))
{
	t_list	*tmp_1;
	t_list	*tmp_2;

	if (!lst || !*lst || !link || !del)
		return ;
	tmp_1 = *lst;
	if (*lst == link)
	{
		*lst = (*lst)->next;
		ft_lstdelone(&tmp_1, del);
		return ;
	}
	while (tmp_1->next && tmp_1->next != link)
		tmp_1 = tmp_1->next;
	if (!tmp_1->next)
		return ;
	tmp_2 = tmp_1->next;
	tmp_1->next = tmp_1->next->next;
	ft_lstdelone(&tmp_2, del);
}
