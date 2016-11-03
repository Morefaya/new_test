/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:07:20 by jcazako           #+#    #+#             */
/*   Updated: 2015/12/01 11:23:13 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_i;
	unsigned char	*s2_i;

	s1_i = (unsigned char*)s1;
	s2_i = (unsigned char*)s2;
	while (n--)
	{
		if (*s1_i != *s2_i)
		{
			return (*s1_i - *s2_i);
		}
		s1_i++;
		s2_i++;
	}
	return (0);
}
