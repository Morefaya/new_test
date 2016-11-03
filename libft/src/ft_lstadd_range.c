/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:47:35 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/06 16:51:12 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_range(t_list **lst, t_list *new, int range)
{
	int		i;
	t_list	*tmp_1;
	t_list	*tmp_2;

	if (!lst || !new)
		return ;
	else if (range <= 0)
		return ;
	if (range == 1)
		ft_lstadd(lst, new);
	else if (range > ft_lstcount(*lst))
		ft_lstadd_back(*lst, new);
	i = 2;
	tmp_1 = *lst;
	while (tmp_1->next && i++ < range)
		tmp_1 = tmp_1->next;
	if (!tmp_1->next)
		return ;
	tmp_2 = tmp_1->next;
	tmp_1->next = new;
	new->next = tmp_2;
}
