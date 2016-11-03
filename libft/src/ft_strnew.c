/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 19:12:06 by jcazako           #+#    #+#             */
/*   Updated: 2015/12/08 18:09:53 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*new;

	new = (char*)malloc(size * sizeof(*new) + 1);
	if (!new)
	{
		return (NULL);
	}
	ft_memset(new, 0, size + 1);
	return (new);
}
