/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 16:52:21 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/30 16:52:45 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_plus(t_opt opt, int *ret)
{
	if (opt.attri.plus && ft_check_charset(opt.type, "diD"))
	{
		(*ret)++;
		return (1);
	}
	return (0);
}

int	print_moins(t_opt opt, int *ret)
{
	if (check_signe_moins(opt) == -1)
	{
		(*ret)++;
		return (1);
	}
	return (0);
}
