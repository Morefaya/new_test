/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordnb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 16:58:57 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/04 17:38:58 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordnb(char *str)
{
	int	nb;

	nb = 0;
	if (!str)
		return (0);
	while (*str)
	{
		while (*str && ft_check_charset(*str, " \t\n"))
			str++;
		if (*str)
		{
			nb++;
			while (*str && !ft_check_charset(*str, " \t\n"))
				str++;
		}
	}
	return (nb);
}
