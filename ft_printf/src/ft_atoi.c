/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:02:55 by jcazako           #+#    #+#             */
/*   Updated: 2015/11/30 14:48:36 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int nbr;
	int	signe;

	nbr = 0;
	signe = 1;
	while (ft_check_charset(*str, " \t\n\v\r\f"))
	{
		str++;
	}
	if (*str == '-' && ft_chisdigit(*(str + 1)))
	{
		signe = -1;
		str++;
	}
	else if (*str == '+' && ft_chisdigit(*(str + 1)))
	{
		str++;
	}
	while (ft_chisdigit(*str))
	{
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	return (signe * nbr);
}
