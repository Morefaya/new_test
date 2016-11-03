/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 20:11:57 by jcazako           #+#    #+#             */
/*   Updated: 2016/05/17 20:12:33 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		char_cmp_base(char a, char *base)
{
	int i;

	i = 0;
	while (base[i] && base[i] != a)
	{
		i++;
	}
	return (i);
}

int		atoi_base(char *nb_base, char *base)
{
	int i;
	int nb;
	int len_base;

	i = 0;
	nb = 0;
	len_base = ft_strlen(base);
	while (nb_base[i])
	{
		nb = nb * len_base + char_cmp_base(nb_base[i], base);
		i++;
	}
	return (nb);
}
