/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 12:48:44 by jcazako           #+#    #+#             */
/*   Updated: 2015/12/07 12:55:09 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	if (fd >= 0)
	{
		if (nbr == -2147483648)
		{
			ft_putstr_fd("-2147483648", fd);
			return ;
		}
		if (nbr < 0)
		{
			nbr *= -1;
			ft_putchar_fd('-', fd);
		}
		if (nbr > 9)
		{
			ft_putnbr_fd(nbr / 10, fd);
			ft_putnbr_fd(nbr % 10, fd);
		}
		else
		{
			ft_putchar_fd('0' + nbr, fd);
		}
	}
}
