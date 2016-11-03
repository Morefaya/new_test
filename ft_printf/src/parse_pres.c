/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pres.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:12:11 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/25 17:35:01 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_pres(const char **format, t_opt *opt)
{
	int	pres;
	int	ret;

	pres = 0;
	ret = 0;
	if (**format == '.')
	{
		(*format)++;
		opt->pres_on = 1;
	}
	if (ft_check_charset(**format, "-1234567890"))
	{
		ret = 1;
		opt->pres_on = 1;
		pres = ft_atoi(*format);
		if (pres < 0)
			pres = 0;
		opt->presi = pres;
		if (**format == '-')
			(*format)++;
		while (ft_check_charset(**format, "1234567890"))
			(*format)++;
	}
	return (ret);
}
