/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:52:49 by jcazako           #+#    #+#             */
/*   Updated: 2015/11/27 19:18:42 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char c_i;

	c_i = (char)c;
	while (*str)
	{
		if (*str == c_i)
		{
			return ((char*)str);
		}
		str++;
	}
	if (*str == c_i)
	{
		return ((char*)str);
	}
	return (NULL);
}
