/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:51:31 by jcazako           #+#    #+#             */
/*   Updated: 2016/01/26 20:37:53 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	char			*str_n;

	str_n = NULL;
	if (str)
	{
		if (!(str_n = ft_strnew(len)))
			return (NULL);
		ft_strncpy(str_n, str + start, len);
	}
	return (str_n);
}
