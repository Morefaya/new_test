/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trdelone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 22:27:23 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/05 22:27:24 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_trdelone(t_tree **atr, void (*del)(void*, size_t))
{
	if (del && atr)
		del((*atr)->content, (*atr)->content_size);
	ft_memdel((void**)atr);
}
