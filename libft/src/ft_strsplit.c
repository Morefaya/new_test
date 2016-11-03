/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 11:17:11 by jcazako           #+#    #+#             */
/*   Updated: 2016/01/26 20:08:53 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		gt_wordnb(const char *str, char a)
{
	int		i;

	i = 0;
	if (!str || !a)
		return (0);
	while (*str)
	{
		while (*str == a)
			str++;
		if (*str && *str != a)
		{
			while (*str && *str != a)
				str++;
			i++;
		}
	}
	return (i);
}

static int		gt_wordln(const char *str, char a)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != a)
		i++;
	return (i);
}

static char		*gt_word(const char **str, char a)
{
	int		len_w;
	char	*word;
	int		i;

	while (**str == a)
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
	while (**str == a)
		(*str)++;
	return (word);
}

static char		**ft_strnull(void)
{
	char	**tab;

	tab = NULL;
	if (!(tab = (char**)malloc(sizeof(*tab) + 1)))
		return (NULL);
	*tab = NULL;
	return (tab);
}

char			**ft_strsplit(const char *str, char a)
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
