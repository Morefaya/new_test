/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:42:58 by jcazako           #+#    #+#             */
/*   Updated: 2016/05/17 21:40:59 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	size_base(t_opt opt)
{
	unsigned long	base;

	if (ft_check_charset(opt.type, "oO"))
		base = 8;
	else if (ft_check_charset(opt.type, "xXp"))
		base = 16;
	else if (ft_check_charset(opt.type, "CS"))
		base = 2;
	else
		base = 10;
	change_signe(&opt);
	if (ft_check_charset(opt.type, "uUxXoOp"))
		return (szb_ul(opt, base));
	else if (opt.type == 'D' || (ft_check_charset(opt.type, "di")
		&& ft_check_charset(opt.m_len, "lL")))
		return (szb_l(opt, base));
	else if (ft_check_charset(opt.type, "di") && opt.m_len == 'h')
		return (szb_s(opt, base));
	else if (ft_check_charset(opt.type, "di") && opt.m_len == 'H')
		return (szb_c(opt, base));
	else
		return (szb_i(opt, base));
	return (0);
}
