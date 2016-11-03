/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:30:19 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/30 16:19:09 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_space_right(t_opt opt, int ret_p)
{
	int	size;
	int	ret;

	ret = 0;
	size = opt.width - ret_p;
	while (size > 0)
	{
		ft_putchar(' ');
		ret++;
		size--;
	}
	return (ret);
}

int			print_nbr(t_opt opt)
{
	int	ret;

	ret = 0;
	ret += print_space_left(opt);
	ret += print_prefix(opt, 1);
	ret += print_zero_left(opt, 1);
	ret += print_choice(opt);
	if (opt.attri.moins)
		ret += print_space_right(opt, ret);
	return (ret);
}
