/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlong_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 21:08:53 by jcazako           #+#    #+#             */
/*   Updated: 2016/05/17 21:09:08 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		putlong_nbr(long nbr, int *ret)
{
	if (nbr == LONG_MIN)
	{
		ft_putstr("9223372036854775808");
		(*ret) += 19;
		return ;
	}
	if (nbr > 9)
	{
		putlong_nbr(nbr / 10, ret);
		putlong_nbr(nbr % 10, ret);
	}
	else
	{
		ft_putchar('0' + nbr);
		(*ret)++;
	}
}
