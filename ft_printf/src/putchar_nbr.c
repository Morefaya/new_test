/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 20:23:49 by jcazako           #+#    #+#             */
/*   Updated: 2016/05/17 20:23:56 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putchar_nbr(char nbr, int *ret)
{
	if (nbr == CHAR_MIN)
	{
		ft_putstr("128");
		(*ret) += 3;
		return ;
	}
	if (nbr < 0)
		nbr *= -1;
	if (nbr > 9)
	{
		putchar_nbr(nbr / 10, ret);
		putchar_nbr(nbr % 10, ret);
	}
	else
	{
		ft_putchar('0' + nbr);
		(*ret)++;
	}
}
