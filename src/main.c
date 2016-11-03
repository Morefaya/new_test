#include "libft.h"
#include "ft_printf.h"
#include <fcntl.h>

#define OPT_A 01
#define OPT_B 02
#define OPT_C 04
#define OPT_FLAG "abc"

typedef struct s_line
{
	char	*line;
}		t_line;

void	read_line(int fd, t_list **lst)
{
	char	*line;
	t_list	*tmp;
	t_line	content;

	while (get_next_line(fd, &line) > 0)
	{
		content.line = line;
		if (!(tmp = ft_lstnew(&content, sizeof(content))))
			return ;
		if (!*lst)
			ft_lstadd(lst, tmp);
		else
			ft_lstadd_back(*lst, tmp);
	}
	free(line);
}

void	print_line(t_list *l_lst)
{
	char	*str;
	while (l_lst)
	{
		str = ((t_line*)(l_lst->content))->line;
		ft_printf("%s\n", str);
		l_lst = l_lst->next;
	}
}

int	check_opt(char *str, int *opt)
{
	int	i;
	i = 0;
	if (str[i] == '-')
		i++;
	else
		return (1);
	while (str[i])
	{
		if (!ft_strchr(OPT_FLAG, str[i]))
		{
			return (2);
		}
		else
		{
			if (str[i] == 'a')
				*opt |= OPT_A;
			else if (str[i] == 'b')
				*opt |= OPT_B;
			else
				*opt |= OPT_C;
		}
		i++;
	}
	return (0);
}

void	del_line(t_line *line, size_t size)
{
	free(line->line);
	ft_bzero(line, size);
	free(line);
}

int	main(int ac, char **av)
{
	t_list	*lst;
	int	i;
	int	fd;
	int	cond;
	int	opt;
	int	ret;

	lst = NULL;
	fd = 0;
	i = 1;
	cond = 0;
	opt = 0;
	if (ac == 1)
		read_line(0, &lst);
	while (i < ac)
	{
		if (av[i][0] == '-' && !cond)
		{
			if ((ret = check_opt(av[i], &opt)))
			{
				ft_printf("invalid option\n");
				ft_lstdel(&lst, (void(*)(void*, size_t))del_line);
				return (ret);
			}
		}
		else if (i == ac && !cond)
		{
			read_line(0, &lst);
		}
		else
		{
			cond = 1;
			if ((fd = open(av[i], O_RDONLY)) < 0)
			{
				ft_printf("no such file: %s\n", av[i]);
				ft_lstdel(&lst, (void(*)(void*, size_t))del_line);
				return (3);
			}
			read_line(fd, &lst);
			close(fd);
		}
		i++;
	}
	if (opt)
		ft_printf("opt : %d\n", opt);
	print_line(lst);
	ft_lstdel(&lst, (void(*)(void*, size_t))del_line);
	return (0);
}
