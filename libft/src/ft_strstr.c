/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:37:06 by jcazako           #+#    #+#             */
/*   Updated: 2015/12/08 17:17:15 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	while (*s1)
	{
		if (!ft_strncmp(s1, s2, ft_strlen(s2)))
		{
			return ((char*)s1);
		}
		s1++;
	}
	if (!ft_strncmp(s1, s2, ft_strlen(s2)))
	{
		return ((char*)s1);
	}
	return (NULL);
}
