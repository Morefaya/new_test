/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:22:56 by jcazako           #+#    #+#             */
/*   Updated: 2015/11/28 18:55:57 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*new;

	len = 0;
	new = NULL;
	len = ft_strlen(str);
	new = (char*)malloc(len * sizeof(*new) + 1);
	if (!new)
	{
		return (NULL);
	}
	ft_strcpy(new, str);
	return (new);
}
