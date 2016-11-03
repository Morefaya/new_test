/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 11:12:32 by jcazako           #+#    #+#             */
/*   Updated: 2015/12/07 15:56:21 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t		sz_begin_blank(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_check_charset(str[i], " \n\t"))
		{
			return (i);
		}
		i++;
	}
	return (i);
}

static size_t		sz_end_blank(const char *str)
{
	int		i;
	size_t	len;

	i = ft_strlen(str) - 1;
	len = 0;
	while (i >= 0)
	{
		if (!ft_check_charset(str[i], " \n\t"))
		{
			return (len);
		}
		i--;
		len++;
	}
	return (len);
}

static size_t		gt_size(const char *str)
{
	size_t	len;
	size_t	sz_bn;
	size_t	sz_ed;
	int		size;

	len = ft_strlen(str);
	sz_bn = sz_begin_blank(str);
	sz_ed = sz_end_blank(str);
	size = len - sz_bn - sz_ed;
	if (size < 0)
	{
		return (0);
	}
	return (size);
}

char				*ft_strtrim(const char *str)
{
	int		size;
	size_t	sz_bn;
	char	*trim;
	int		i;

	if (!str)
	{
		return (NULL);
	}
	size = gt_size(str);
	sz_bn = sz_begin_blank(str);
	i = 0;
	trim = (char*)malloc(sizeof(*trim) * size + 1);
	if (!trim)
	{
		return (NULL);
	}
	while (i < size)
	{
		trim[i] = str[sz_bn + i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}
