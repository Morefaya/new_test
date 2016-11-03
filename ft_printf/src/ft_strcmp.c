/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:23:12 by jcazako           #+#    #+#             */
/*   Updated: 2015/12/07 17:02:23 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*s1_i;
	unsigned char	*s2_i;
	size_t			i;

	s1_i = (unsigned char*)s1;
	s2_i = (unsigned char*)s2;
	i = 0;
	while (s1_i[i] && s2_i[i] && s1_i[i] == s2_i[i])
	{
		i++;
	}
	return ((s1_i[i] - s2_i[i]));
}
