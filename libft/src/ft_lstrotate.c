/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 22:28:24 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/05 22:28:28 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrotate(t_list **lst)
{
	t_list	*tmp_1;
	t_list	*tmp_2;

	if (!*lst)
		return ;
	else if (!(*lst)->next)
		return ;
	tmp_1 = *lst;
	*lst = (*lst)->next;
	tmp_1->next = NULL;
	tmp_2 = *lst;
	while (tmp_2->next)
		tmp_2 = tmp_2->next;
	tmp_2->next = tmp_1;
}
