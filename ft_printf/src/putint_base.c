/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putint_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 20:24:23 by jcazako           #+#    #+#             */
/*   Updated: 2016/05/17 20:25:22 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putint_base(int nb, char *base)
{
	unsigned int len;
	unsigned int nb_u;

	len = ft_strlen(base);
	nb_u = nb;
	if (nb_u > len - 1)
	{
		putint_base(nb_u / len, base);
		putint_base(nb_u % len, base);
		return ;
	}
	ft_putchar(base[nb_u]);
	return ;
}
