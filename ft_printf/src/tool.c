/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 20:55:52 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/30 16:42:08 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int		nbrlen(t_opt opt)
{
	int	len;

	len = size_base(opt);
	if (opt.presi > len)
		return (opt.presi);
	else
		return (len);
}

int		check_signe_moins(t_opt opt)
{
	if (ft_check_charset(opt.type, "di"))
	{
		if ((!opt.m_len && (int)opt.conv < 0)
			|| (opt.m_len == 'h' && (short)opt.conv < 0)
			|| (opt.m_len == 'H' && (char)opt.conv < 0)
			|| (ft_check_charset(opt.m_len, "lL") && opt.conv < 0)
			|| (opt.m_len == 'j' && opt.conv < 0)
			|| (opt.m_len == 'z' && opt.conv < 0))
			return (-1);
	}
	else if ((opt.type == 'D' && opt.conv < 0)
			|| (opt.type == 'C' && (int)opt.conv < 0))
		return (-1);
	return (1);
}

void	change_signe(t_opt *opt)
{
	if (ft_check_charset(opt->type, "di"))
	{
		if (!opt->m_len && (int)opt->conv < 0)
			opt->conv = (int)opt->conv * -1;
		else if (opt->m_len == 'h' && (short)opt->conv < 0)
			opt->conv = (short)opt->conv * -1;
		else if (opt->m_len == 'H' && (char)opt->conv < 0)
			opt->conv = (char)opt->conv * -1;
		else if (ft_check_charset(opt->m_len, "lL") && opt->conv < 0)
			opt->conv *= -1;
	}
	else if (opt->type == 'D' && opt->conv < 0)
		opt->conv *= -1;
}

int		print_prefix(t_opt opt, int cond)
{
	if (!opt.conv && opt.type != 'p')
		return (0);
	if ((ft_check_charset(opt.type, "xX") && opt.attri.diez) || opt.type == 'p')
	{
		if (cond)
		{
			if (ft_check_charset(opt.type, "xp"))
				ft_putstr("0x");
			else
				ft_putstr("0X");
		}
		return (2);
	}
	return (0);
}

void	print_c(long ret)
{
	if (ret > 0x7F)
		print_c(ret >> 8);
	ret &= 0xFF;
	if (ret)
		write(1, &ret, 1);
}
