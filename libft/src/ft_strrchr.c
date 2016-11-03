/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 10:33:24 by jcazako           #+#    #+#             */
/*   Updated: 2015/11/28 11:17:44 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char		c_i;
	const char	*last_c;

	c_i = (char)c;
	last_c = NULL;
	while (*str)
	{
		if (*str == c_i)
		{
			last_c = str;
		}
		str++;
	}
	if (*str == c_i)
	{
		last_c = str;
	}
	return ((char*)last_c);
}
