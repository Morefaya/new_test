/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 17:12:07 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/04 19:05:51 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_str(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (*str)
	{
		while (*str && ft_check_charset(*str, " \t\n"))
			str++;
		while (*str && !ft_check_charset(*str, " \t\n"))
		{
			len++;
			str++;
		}
	}
	return (len);
}
