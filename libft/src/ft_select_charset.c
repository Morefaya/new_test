/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_charset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 17:28:41 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/04 17:28:56 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_select_charset(char ch, const char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == ch)
			return (i);
		i++;
	}
	return (-1);
}
