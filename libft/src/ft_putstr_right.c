/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:59:32 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/18 18:44:47 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_right(char *str, int width)
{
	int	len;
	int diff;

	len = (int)ft_strlen(str);
	if ((diff = width - len) >= 0)
	{
		while ((diff--))
			ft_putchar(' ');
		ft_putstr(str);
	}
	else
	{
		diff *= -1;
		while (diff <= len && str[diff])
		{
			ft_putchar(str[diff]);
			diff++;
		}
	}
}
