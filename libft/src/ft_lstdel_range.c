/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:28:27 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/06 16:28:49 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_range(t_list **lst, int range, void (del)(void*, size_t))
{
	t_list	*tmp_1;
	t_list	*tmp_2;
	int		i;

	if (!lst || !*lst || !del)
		return ;
	else if (range <= 0 || range > ft_lstcount(*lst))
		return ;
	tmp_1 = *lst;
	if (range == 1)
	{
		*lst = (*lst)->next;
		ft_lstdelone(&tmp_1, del);
		return ;
	}
	i = 2;
	while (tmp_1->next && i++ < range)
		tmp_1 = tmp_1->next;
	if (!tmp_1->next)
		return ;
	tmp_2 = tmp_1->next;
	tmp_1->next = tmp_1->next->next;
	ft_lstdelone(&tmp_2, del);
}
