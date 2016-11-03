/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:23:28 by jcazako           #+#    #+#             */
/*   Updated: 2015/11/30 14:42:30 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_charset(char a, const char *charset)
{
	while (*charset)
	{
		if (*charset == a)
		{
			return (1);
		}
		charset++;
	}
	return (0);
}
