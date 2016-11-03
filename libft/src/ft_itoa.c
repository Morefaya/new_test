/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:05:23 by jcazako           #+#    #+#             */
/*   Updated: 2015/12/08 18:18:07 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_check_negative(int *nbr, int *signe)
{
	if (*nbr < 0)
	{
		*nbr *= -1;
		*signe = 1;
	}
}

static void	ft_putnbr_instr(int c, char **str)
{
	if (c > 9)
	{
		ft_putnbr_instr(c / 10, str);
		ft_putnbr_instr(c % 10, str);
	}
	else
	{
		**str = '0' + c;
		(*str)++;
	}
}

char		*ft_itoa(int c)
{
	char	**p_str;
	char	*str;
	int		signe;

	p_str = NULL;
	str = NULL;
	signe = 0;
	if (c == -2147483648)
		return (ft_strdup("-2147483648"));
	ft_check_negative(&c, &signe);
	str = ft_strnew((size_t)ft_size_base(c, 10) + signe);
	if (!str)
		return (NULL);
	p_str = &str;
	if (signe == 1)
	{
		*str++ = '-';
		ft_putnbr_instr(c, p_str);
	}
	else
		ft_putnbr_instr(c, p_str);
	return (*p_str - ft_size_base(c, 10) - signe);
}
