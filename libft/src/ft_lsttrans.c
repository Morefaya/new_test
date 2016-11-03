/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttrans.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 22:30:11 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/05 22:30:13 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lsttrans(t_list **lst, int range)
{
	int	i;

	if (!range)
		return ;
	i = ft_abs(range);
	while (i--)
	{
		if (range < 0)
			ft_lstrev_rotate(lst);
		ft_lstswap(lst);
		if (range > 0)
			ft_lstrotate(lst);
	}
}
