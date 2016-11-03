/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 17:32:17 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/04 17:32:20 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	gt_wordnb(const char *str, char *a)
{
	int	i;

	i = 0;
	if (!str || !a)
		return (0);
	while (*str)
	{
		while (ft_check_charset(*str, a))
			str++;
		if (*str && !ft_check_charset(*str, a))
		{
			while (*str && !ft_check_charset(*str, a))
				str++;
			i++;
		}
	}
	return (i);
}

static int	gt_wordln(const char *str, char *a)
{
	int	i;

	i = 0;
	while (str[i] && !ft_check_charset(str[i], a))
		i++;
	return (i);
}

static char	*gt_word(const char **str, char *a)
{
	int		len_w;
	char	*word;
	int		i;

	while (ft_check_charset(**str, a))
		(*str)++;
	len_w = gt_wordln(*str, a);
	if (!(word = ft_strnew(len_w)))
		return (NULL);
	i = 0;
	while (i < len_w)
	{
		word[i] = *(*str)++;
		i++;
	}
	while (ft_check_charset(**str, a))
		(*str)++;
	return (word);
}

static char	**ft_strnull(void)
{
	char	**tab;

	tab = NULL;
	if (!(tab = (char**)malloc(sizeof(*tab) + 1)))
		return (NULL);
	*tab = NULL;
	return (tab);
}

char		**ft_strstr_split(const char *str, char *a)
{
	int		nb_word;
	char	**tab;

	nb_word = gt_wordnb(str, a);
	tab = NULL;
	if (!str || !a || !nb_word)
		return (ft_strnull());
	if (!(tab = (char**)malloc(sizeof(*tab) * nb_word + 1)))
		return (NULL);
	while (*str)
		*tab++ = gt_word(&str, a);
	*tab = NULL;
	return (tab - nb_word);
}
