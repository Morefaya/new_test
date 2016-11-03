/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_attr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 11:00:00 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/30 16:21:03 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	init_attr(const char *format, t_attr *attr)
{
	int	ret;

	ret = 0;
	if (ft_check_charset(*format, "#0-+ "))
		ret = 1;
	if (*format == '#')
		attr->diez = 1;
	else if (*format == '0')
		attr->zero = 1;
	else if (*format == '-')
		attr->moins = 1;
	else if (*format == '+')
		attr->plus = 1;
	else if (*format == ' ')
		attr->space = 1;
	return (ret);
}

int			parse_attr(const char **format, t_attr *attr)
{
	int	ret;

	ret = 0;
	while (ft_check_charset((char)(**format), ATTR))
	{
		if (init_attr(*format, attr))
			ret = 1;
		(*format)++;
	}
	return (ret);
}
