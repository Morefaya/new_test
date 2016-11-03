/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 22:27:13 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/05 22:27:15 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_trdel(t_tree **atr, void (*del)(void*, size_t))
{
	if (!atr || !del)
		return ;
	if (!*atr)
		return ;
	if ((*atr)->left)
		ft_trdel(&(*atr)->left, del);
	if ((*atr)->right)
		ft_trdel(&(*atr)->right, del);
	ft_trdelone(atr, del);
}
