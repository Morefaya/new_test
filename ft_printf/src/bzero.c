/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:47:03 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/25 17:31:40 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	bzero_attr(t_opt *opt)
{
	opt->attri.diez = 0;
	opt->attri.zero = 0;
	opt->attri.moins = 0;
	opt->attri.plus = 0;
	opt->attri.space = 0;
}

void	bzero_opt(t_opt *opt)
{
	bzero_attr(opt);
	opt->width = 0;
	opt->pres_on = 0;
	opt->presi = 0;
	opt->m_len = '\0';
	opt->type = '\0';
	opt->conv = 0;
}
