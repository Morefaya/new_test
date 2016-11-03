/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 16:06:39 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/30 16:07:29 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_after(t_opt opt, int *i, int *ret)
{
	if (opt.width && opt.attri.moins)
	{
		while ((*i)++ < opt.width - 1)
		{
			if (!opt.pres_on)
				ft_putchar(' ');
			else
				ft_putchar('0');
		}
		(*ret) += --(*i);
	}
	(*ret)++;
}

static void	print_before(t_opt opt, int *i, int *ret)
{
	if (opt.width && !opt.attri.moins)
	{
		while ((*i)++ < opt.width - 1)
		{
			if (!opt.pres_on)
				ft_putchar(' ');
			else
				ft_putchar('0');
		}
		(*ret) += --(*i);
	}
}

static void	parsing(const char **format, t_opt *opt, int *ret)
{
	*ret = 0;
	if (parse_attr(format, &(opt->attri)))
		*ret = 1;
	if (parse_width(format, opt))
		*ret = 1;
	if (parse_pres(format, opt))
		*ret = 1;
	if (ft_check_charset(**format, "lhjz"))
	{
		if (parse_modifier(format, opt))
			*ret = 1;
	}
}

int			print_var(const char **format, va_list ap)
{
	int		ret;
	t_opt	opt;
	int		conv;
	int		i;

	bzero_opt(&opt);
	i = 0;
	while (!ft_check_charset(**format, CONV))
	{
		parsing(format, &opt, &ret);
		if (!ret)
			break ;
	}
	if (!(conv = get_conv(format, ap, &opt)))
	{
		print_before(opt, &i, &ret);
		ft_putchar(**format);
		print_after(opt, &i, &ret);
		(*format)++;
		return (ret);
	}
	modify_len(&opt);
	ret = print(opt);
	(*format)++;
	return (ret);
}
