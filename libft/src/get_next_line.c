/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:39:32 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/01 20:37:50 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl		*rd_list(t_list **list, const int fd)
{
	t_gnl			content;
	t_list			*lst_tmp;

	if (fd < 0 || !list)
		return (NULL);
	lst_tmp = *list;
	while (lst_tmp)
	{
		if (((t_gnl*)(lst_tmp->content))->fd == fd)
			return (lst_tmp->content);
		lst_tmp = lst_tmp->next;
	}
	content.fd = fd;
	if (!(content.str = ft_strnew(BUFF_SIZE)))
		return (NULL);
	if (!(lst_tmp = ft_lstnew(&content, sizeof(content))))
	{
		free(content.str);
		return (NULL);
	}
	ft_lstadd(list, lst_tmp);
	return ((*list)->content);
}

static int			gnl(char **line, char **str)
{
	int				ret;
	char			*tmp;

	ret = 0;
	if ((tmp = ft_strchr(*str, '\n')))
	{
		*tmp = '\0';
		if (!(*line = ft_strdup(*str)))
			return (-1);
		tmp++;
		ft_strcpy(*str, tmp);
		ret = 1;
	}
	else if (ft_strlen(*str))
	{
		if (!(*line = ft_strdup(*str)))
			return (-1);
		**str = '\0';
		ret = 1;
	}
	else if (!(*line = ft_strnew(0)))
		return (-1);
	return (ret);
}

static int			read_fd(t_gnl **content)
{
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

	while (!ft_strchr((*content)->str, '\n'))
	{
		ft_bzero(buff, BUFF_SIZE + 1);
		if ((ret = read((*content)->fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		if (!ret)
			return (0);
		tmp = (*content)->str;
		if (!((*content)->str = ft_strjoin((*content)->str, buff)))
			return (-1);
		free(tmp);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_gnl			*gnl_data;
	int				ret;

	if (BUFF_SIZE <= 0 || !line || !(gnl_data = rd_list(&list, fd)))
		return (-1);
	if ((ret = read_fd(&gnl_data)) == -1)
		return (-1);
	return (gnl(line, &(gnl_data->str)));
}
