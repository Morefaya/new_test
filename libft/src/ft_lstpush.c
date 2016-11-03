/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 22:28:13 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/05 22:28:15 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

	if (!*lst_a)
		return ;
	tmp = *lst_b;
	*lst_b = *lst_a;
	*lst_a = (*lst_a)->next;
	(*lst_b)->next = tmp;
}
