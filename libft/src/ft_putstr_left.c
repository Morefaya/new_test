/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:48:56 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/18 18:47:03 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_left(char *str, int width)
{
	while (*str && width)
	{
		ft_putchar(*str++);
		width--;
	}
	while ((width--))
		ft_putchar(' ');
}
