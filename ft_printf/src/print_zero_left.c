/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zero_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 17:04:01 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/30 17:05:27 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		deal_zero(t_opt opt, int *size, int *ret, int cond)
{
	if (opt.attri.moins && opt.attri.zero && opt.conv)
		return ;
	else if (opt.attri.moins && opt.attri.diez && opt.attri.zero)
		return ;
	if (ft_check_charset(opt.type, "dD") && opt.attri.plus
		&& opt.attri.zero && opt.width && (int)opt.conv < 0)
		(*size)++;
	while (*size > 0)
	{
		if (cond)
			ft_putchar('0');
		(*ret)++;
		(*size)--;
	}
}

static void		help_norme(t_opt opt, int *size)
{
	if (opt.attri.zero && !opt.pres_on && opt.width)
	{
		*size = opt.width - size_base(opt);
		if (check_signe_moins(opt) == -1)
			(*size)--;
	}
	else
		*size = opt.presi - size_base(opt);
	if ((opt.type == 'p' && opt.attri.zero && opt.width))
		(*size) -= 2;
	else if ((ft_check_charset(opt.type, "diD")
		&& opt.attri.moins && opt.attri.zero)
		|| (ft_check_charset(opt.type, "diD")
		&& opt.attri.plus && opt.attri.zero && opt.conv))
		(*size)--;
	else if (ft_check_charset(opt.type, "xX")
		&& opt.attri.zero && opt.attri.diez)
		(*size) -= 2;
}

int				print_zero_left(t_opt opt, int cond)
{
	int	size;
	int	ret;

	ret = 0;
	size = 0;
	help_norme(opt, &size);
	if (ft_check_charset(opt.type, "dDi") && opt.attri.zero && !opt.attri.diez
		&& opt.width && !opt.pres_on && !opt.presi && !opt.conv)
	{
		if ((opt.attri.plus && !opt.attri.space && !opt.attri.moins)
			|| (!opt.attri.plus && opt.attri.space && !opt.attri.moins)
			|| (!opt.attri.plus && !opt.attri.space && opt.attri.moins))
			size--;
	}
	deal_zero(opt, &size, &ret, cond);
	if (!ret && opt.attri.diez && ft_check_charset(opt.type, "oO"))
	{
		if (cond && opt.conv)
		{
			ft_putchar('0');
			ret++;
		}
	}
	return (ret);
}
