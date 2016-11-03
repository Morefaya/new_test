/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_pres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 11:58:32 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/28 12:07:49 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putstr_pres(t_opt opt, int *ret, int cond)
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)opt.conv;
	if (str)
	{
		while (*str)
		{
			if (opt.pres_on && i++ == opt.presi)
				break ;
			if (cond)
				ft_putchar(*str);
			(*ret)++;
			str++;
		}
	}
}
