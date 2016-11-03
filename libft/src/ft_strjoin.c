/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 14:23:52 by jcazako           #+#    #+#             */
/*   Updated: 2016/01/26 19:03:26 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;

	join = NULL;
	if (s1 || s2)
	{
		if (!(join = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		if (s1)
			ft_strcpy(join, s1);
		if (s2)
			ft_strcat(join, s2);
	}
	return (join);
}
