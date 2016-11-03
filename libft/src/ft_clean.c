/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 16:52:27 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/04 20:12:35 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_clean(char *str)
{
	char	*str_clean;
	int		nb_wd;
	int		word_str_len;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	nb_wd = ft_wordnb(str);
	word_str_len = ft_strlen_str(str);
	if (!(str_clean = ft_strnew(word_str_len + nb_wd - 1)))
		return (NULL);
	while (*str)
	{
		while (*str && ft_check_charset(*str, " \t\n"))
			str++;
		while (*str && !ft_check_charset(*str, " \t\n"))
			str_clean[i++] = *str++;
		if (*str && i < word_str_len + nb_wd)
			str_clean[i++] = ' ';
	}
	return (str_clean);
}
