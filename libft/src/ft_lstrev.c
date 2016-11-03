/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 16:36:44 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/08 16:36:45 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **lst)
{
	t_list	*trash;

	trash = NULL;
	while (*lst)
	{
		ft_lstrev_rotate(lst);
		ft_lstpush(lst, &trash);
	}
	while (trash)
		ft_lstpush(&trash, lst);
}
