/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 17:26:15 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/04 17:26:57 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	deal_base(const char **str, int *base)
{
	if (ft_check_charset(**(str + 1), "xX"))
	{
		(*str)++;
		if (ft_chisdigit(**(str + 1)))
		{
			*base = 16;
			(*str)++;
		}
	}
	else if (ft_chisdigit(**(str + 1)))
	{
		*base = 8;
		(*str)++;
	}
}

int			ft_getnbr(const char *str)
{
	int	nbr;
	int	signe;
	int	base;

	nbr = 0;
	signe = 1;
	base = 10;
	while (ft_check_charset(*str, " \t\n\v\r\f"))
		str++;
	if (ft_check_charset(*str, "-+")
			&& ft_check_charset(*(str + 1), "123456789"))
	{
		signe = (*str == '-') ? -1 : 1;
		str++;
	}
	else if (*str == '0')
		deal_base(&str, &base);
	while (ft_chisdigit(*str))
	{
		nbr = nbr * base + *str - '0';
		str++;
	}
	return (signe * nbr);
}
