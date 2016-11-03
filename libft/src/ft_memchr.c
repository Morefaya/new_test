/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:20:04 by jcazako           #+#    #+#             */
/*   Updated: 2016/01/26 20:35:24 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	stop;
	unsigned char	*s_i;

	stop = (unsigned char)c;
	s_i = (unsigned char*)s;
	while (n--)
	{
		if (*s_i == stop)
			return ((void*)s_i);
		s_i++;
	}
	return (NULL);
}
