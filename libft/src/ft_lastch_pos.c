/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastch_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:56:30 by jcazako           #+#    #+#             */
/*   Updated: 2015/12/02 14:29:53 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lastch_pos(const char *str)
{
	size_t	len;
	int		i;

	len = 0;
	i = 1;
	if (str && ft_strlen(str))
	{
		len = ft_strlen(str);
		while (i < (int)len && ft_check_charset(str[len - i], " \t\n"))
		{
			i++;
		}
		return (len - i);
	}
	return (0);
}
