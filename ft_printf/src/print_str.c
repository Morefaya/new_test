/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:44:38 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/30 16:38:22 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

static int	putlong_str(t_opt opt, int cond)
{
	int		ret;
	wchar_t	*str;

	ret = 0;
	str = (int*)opt.conv;
	while (*str)
	{
		opt.conv = *str;
		opt.type = 'C';
		ret += putlong_char(opt, cond);
		str++;
	}
	return (ret);
}

static void	print_space(t_opt opt, int *ret)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	if (opt.width)
	{
		if (ft_check_charset(opt.type, "SC") && opt.conv)
			size = putlong_str(opt, 0);
		else if (opt.conv)
			putstr_pres(opt, &size, 0);
		i = opt.width - size;
	}
	while (i-- > 0)
	{
		if (!opt.attri.zero)
			ft_putchar(' ');
		else
			ft_putchar('0');
		(*ret)++;
	}
}

static int	deal_null(t_opt opt, int *i)
{
	if (opt.attri.zero)
	{
		while ((*i)++ < opt.width)
			ft_putchar('0');
		return (opt.width);
	}
	else
	{
		ft_putstr("(null)");
		return (6);
	}
}

int			print_str(t_opt opt)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	if (!opt.conv)
		return (deal_null(opt, &i));
	if (!opt.attri.moins)
		print_space(opt, &ret);
	if (opt.type == 'S' || (opt.type == 's' && opt.m_len == 'l'))
	{
		if (opt.pres_on)
			return (-1);
		ret += putlong_str(opt, 1);
	}
	else
		putstr_pres(opt, &ret, 1);
	if (opt.attri.moins)
		print_space(opt, &ret);
	return (ret);
}
