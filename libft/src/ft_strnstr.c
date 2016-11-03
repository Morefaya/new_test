/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:47:53 by jcazako           #+#    #+#             */
/*   Updated: 2015/12/08 19:03:06 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (!*s2)
		return ((char*)s1);
	while (s1[i] && n > 0)
	{
		k = 0;
		j = i;
		if (n < ft_strlen(s2))
			return (NULL);
		while (s1[j] == s2[k] && s1[j] && s2[k])
		{
			j++;
			k++;
		}
		if (!s2[k])
			return ((char*)s1 + i);
		i++;
		n--;
	}
	return (NULL);
}
