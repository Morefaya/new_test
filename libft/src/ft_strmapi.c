/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:29:48 by jcazako           #+#    #+#             */
/*   Updated: 2015/11/30 19:11:39 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*str_f;

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
			str_f[i] = (*f)(i, str[i]);
			i++;
		}
		str_f[i] = '\0';
	}
	return (str_f);
}
