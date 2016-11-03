/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlong_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 17:02:32 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/30 17:02:43 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	check_base(t_opt opt)
{
	if (ft_check_charset(opt.type, "xXp"))
		return (16);
	else if (ft_check_charset(opt.type, "oO"))
		return (8);
	else
		return (10);
}

void		putlong_base(long nbr, t_opt opt, int *ret)
{
	unsigned long	base;
	char			*base_set;
	unsigned long	n;

	base = check_base(opt);
	n = nbr;
	if (opt.type == 'x' || opt.type == 'X')
		base_set = (opt.type == 'x') ?
			"0123456789abcdef" : "0123456789ABCDEF";
	else if (opt.type == 'o' || opt.type == 'O')
		base_set = "01234567";
	else
		base_set = "0123456789";
	if (n > base - 1)
	{
		putlong_base(n / base, opt, ret);
		putlong_base(n % base, opt, ret);
	}
	else
	{
		ft_putchar(base_set[n]);
		(*ret)++;
	}
}
