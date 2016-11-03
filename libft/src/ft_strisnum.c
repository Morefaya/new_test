/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 17:29:35 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/04 17:31:08 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	deal_base(const char **str)
{
	if (ft_check_charset(**(str + 1), "xX"))
	{
		(*str)++;
		if (ft_chisdigit(**(str + 1)))
			return (1);
	}
	else if (ft_chisdigit(**(str + 1)))
		return (1);
	return (0);
}

int			ft_strisnum(const char *str)
{
	while (ft_check_charset(*str, " \t\n\v\r\f"))
		str++;
	if (ft_check_charset(*str, "+-")
		&& ft_check_charset(*(str + 1), "123456789"))
		return (1);
	else if (*str == '0')
		return (deal_base(&str));
	return (0);
}
