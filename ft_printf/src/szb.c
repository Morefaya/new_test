/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   szb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 21:00:07 by jcazako           #+#    #+#             */
/*   Updated: 2016/05/17 21:41:57 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	szb_ul(t_opt opt, unsigned long base)
{
	int	i;

	i = 1;
	while ((unsigned long)opt.conv >= base)
	{
		opt.conv = (unsigned long)opt.conv / base;
		i++;
	}
	return (i);
}

int	szb_l(t_opt opt, unsigned long base)
{
	int	i;

	i = 1;
	while (opt.conv >= (long)base)
	{
		opt.conv /= (long)base;
		i++;
	}
	return (i);
}

int	szb_s(t_opt opt, unsigned long base)
{
	int	i;

	i = 1;
	while ((short)opt.conv >= (short)base)
	{
		opt.conv = (short)opt.conv / (short)base;
		i++;
	}
	return (i);
}

int	szb_c(t_opt opt, unsigned long base)
{
	int	i;

	i = 1;
	while ((char)opt.conv >= (char)base)
	{
		opt.conv = (char)opt.conv / (char)base;
		i++;
	}
	return (i);
}

int	szb_i(t_opt opt, unsigned long base)
{
	int	i;

	i = 1;
	while ((int)opt.conv >= (int)base)
	{
		opt.conv = (int)opt.conv / (int)base;
		i++;
	}
	return (i);
}
