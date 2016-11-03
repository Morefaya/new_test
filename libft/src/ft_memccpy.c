/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:42:30 by jcazako           #+#    #+#             */
/*   Updated: 2015/11/26 15:37:14 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		stop;
	unsigned char		*dst_i;
	const unsigned char	*src_i;

	stop = (unsigned char)c;
	dst_i = dst;
	src_i = src;
	while (n--)
	{
		if (*src_i == stop)
		{
			*dst_i++ = *src_i;
			return (dst_i);
		}
		else
		{
			*dst_i++ = *src_i++;
		}
	}
	return (0);
}
