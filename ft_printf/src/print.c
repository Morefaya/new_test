/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 14:49:10 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/30 16:29:22 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_after(t_opt opt, int *i, int *ret)
{
	if (opt.width && opt.attri.moins)
	{
		while ((*i)++ < opt.width - 1)
		{
			if (!opt.attri.zero)
			{
				if (!opt.pres_on)
					ft_putchar(' ');
				else
					ft_putchar('0');
			}
			else
				ft_putchar('0');
		}
		(*ret) += --(*i);
	}
}

static void	print_before(t_opt opt, int *i, int *ret)
{
	if (opt.width && !opt.attri.moins)
	{
		while ((*i)++ < opt.width - 1)
		{
			if (!opt.attri.zero)
			{
				if (!opt.pres_on)
					ft_putchar(' ');
				else
					ft_putchar('0');
			}
			else
				ft_putchar('0');
		}
		(*ret) += --(*i);
	}
}

int			print(t_opt opt)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	if (ft_check_charset(opt.type, "pidDoOuUxX"))
		ret += print_nbr(opt);
	else if (opt.type == 's' || opt.type == 'S')
	{
		if (opt.type == 'S' && opt.pres_on)
		{
			while (i++ < opt.width)
				ft_putchar('0');
			return (opt.width);
		}
		ret += print_str(opt);
	}
	else if (opt.type == 'c' || opt.type == 'C')
	{
		print_before(opt, &i, &ret);
		ret += putlong_char(opt, 1);
		print_after(opt, &i, &ret);
	}
	return (ret);
}
