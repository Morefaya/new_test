/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:48:08 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/30 16:18:42 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int			get_conv(const char **format, va_list ap, t_opt *opt)
{
	int	i;

	i = 0;
	if (ft_check_charset(**format, CONV))
	{
		opt->conv = va_arg(ap, long);
		opt->type = **format;
		return (1);
	}
	return (0);
}

void		modify_len(t_opt *opt)
{
	if (ft_check_charset(opt->type, CONV))
	{
		if (ft_check_charset(opt->type, "sSpDUO")
			|| ft_check_charset(opt->m_len, "lLjz"))
			opt->conv &= opt->conv & 0xffffffffffffffff;
		else if (opt->m_len == 'h')
			opt->conv &= opt->conv & 0x000000000000ffff;
		else if (opt->m_len == 'H' || opt->type == 'c')
			opt->conv &= opt->conv & 0x00000000000000ff;
		else
			opt->conv &= opt->conv & 0x00000000ffffffff;
	}
}

static void	deal_percent(const char **format, va_list ap, int *ret)
{
	if (**format != '%')
		(*ret) += print_var(format, ap);
	else
	{
		ft_putchar('%');
		(*format)++;
		(*ret)++;
	}
}

static void	write_str(const char **format, char *next_prc, int *ret)
{
	write(1, *format, next_prc - *format);
	(*ret) += next_prc - *format;
	(*format) += next_prc - *format + 1;
}

int			ft_printf(const char *format, ...)
{
	char	*next_prc;
	int		ret;
	va_list	ap;

	ret = 0;
	va_start(ap, format);
	if (!(ft_strcmp(format, "%")))
		return (0);
	while (*format)
	{
		if ((next_prc = ft_strchr(format, '%')))
			write_str(&format, next_prc, &ret);
		else
		{
			ft_putstr(format);
			ret += ft_strlen(format);
			break ;
		}
		deal_percent(&format, ap, &ret);
	}
	va_end(ap);
	return (ret);
}
