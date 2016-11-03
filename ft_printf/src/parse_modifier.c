/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_modifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 20:14:50 by jcazako           #+#    #+#             */
/*   Updated: 2016/05/17 20:18:20 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_modifier(const char **format, t_opt *opt)
{
	int	ret;

	ret = 0;
	if (ft_check_charset(**format, "lhjz"))
		ret = 1;
	if (**format == 'l')
	{
		if (opt->m_len == 'l')
			opt->m_len = 'L';
		else
			opt->m_len = 'l';
	}
	else if (**format == 'h')
	{
		if (opt->m_len == 'h')
			opt->m_len = 'H';
		else if (opt->m_len == 'H' || !opt->m_len)
			opt->m_len = 'h';
	}
	else if (**format == 'j')
		opt->m_len = 'j';
	else if (**format == 'z')
		opt->m_len = 'z';
	(*format)++;
	return (ret);
}
