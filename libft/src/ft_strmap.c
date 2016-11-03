/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:27:45 by jcazako           #+#    #+#             */
/*   Updated: 2015/11/30 18:27:53 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *str, char (*f)(char))
{
	size_t	i;
	size_t	len;
	char	*str_f;

	i = 0;
	len = 0;
	str_f = NULL;
	if (str && f)
	{
		len = ft_strlen(str);
		str_f = (char*)malloc(len * sizeof(*str_f) + 1);
		if (!str_f)
		{
			return (NULL);
		}
		while (i < len)
		{
			str_f[i] = (*f)(str[i]);
			i++;
		}
		str_f[i] = '\0';
	}
	return (str_f);
}
