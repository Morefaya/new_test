#include "libft.h"

int	ft_maxint(const char *str)
{
	int	i;
	int	signe;
	int	nb;

	signe = 0;
	while (*str && ft_strchr(" \t", *str))
		str++;
	if (*str == '-')
		signe = 1;
	i = 0;
	while (str[i] && ft_strchr("0123456789", str[i]))
		i++;
	nb = ft_atoi(str);
	if (i > 10)
		return (1);
	else if (!signe && nb < 0)
		return (2);
	else if (signe && nb > 0)
		return (3);
	else
		return (0);
}
