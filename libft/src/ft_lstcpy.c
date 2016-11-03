/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 19:16:16 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/17 18:00:12 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy(t_list *lst, size_t c_size)
{
	t_list	*new_cpy;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	if (!(new_cpy = ft_lstnew(lst->content, c_size)))
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew(lst->content, c_size);
		ft_lstadd_back(new_cpy, tmp);
		lst = lst->next;
	}
	return (new_cpy);
}
