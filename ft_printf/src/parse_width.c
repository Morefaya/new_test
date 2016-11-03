/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 11:42:37 by jcazako           #+#    #+#             */
/*   Updated: 2016/05/17 20:19:34 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_width(const char **format, t_opt *opt)
{
	int	width;
	int	ret;

	width = 0;
	ret = 0;
	if (ft_check_charset(**format, "-123456789"))
	{
		ret = 1;
		width = ft_atoi(*format);
		if (width < 0)
		{
			opt->attri.moins = 1;
			width *= -1;
		}
		(*format) += ft_size_base(width, 10);
		opt->width = width;
	}
	return (ret);
}
