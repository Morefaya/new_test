/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 14:25:50 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/30 16:53:55 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include "libft.h"

# define ATTR "#0-+ "
# define CONV "sSpdDioOuUxXcC"
# define MASK_0	0x7F
# define MASK_1 0x1F3F
# define MASK_2 0xF3F3F
# define MASK_3 0x73F3F3F
# define MASK_4 0x33F3F3F3F
# define MASK_5 0x13F3F3F3F3F
# define U_MASK_0 0x0
# define U_MASK_1 0xC080
# define U_MASK_2 0xE08080
# define U_MASK_3 0xF0808080
# define U_MASK_4 0xF880808080
# define U_MASK_5 0xFC8080808080

typedef struct		s_attr
{
	int				diez;
	int				zero;
	int				moins;
	int				plus;
	int				space;
}					t_attr;

typedef struct		s_opt
{
	t_attr			attri;
	int				width;
	int				pres_on;
	int				presi;
	char			m_len;
	char			type;
	long			conv;
}					t_opt;

int					size_base(t_opt opt);
int					putlong_char(t_opt opt, int cond);
void				putlong_base(long nbr, t_opt opt, int *ret);
void				putlong_nbr(long nbr, int *ret);
void				putlun_nbr(unsigned long nbr, t_opt opt, int *ret);
void				putshort_nbr(short nbr, int *ret);
void				putchar_nbr(char nbr, int *ret);

int					parse_attr(const char **str, t_attr *att);
int					parse_width(const char **format, t_opt *opt);

int					parse_modifier(const char **format, t_opt *opt);

int					print_nbr(t_opt opt);
int					print_str(t_opt opt);
int					parse_pres(const char **format, t_opt *opt);

int					print_space_left(t_opt opt);
int					print_zero_left(t_opt opt, int cond);

int					check_signe_moins(t_opt opt);
int					nbrlen(t_opt opt);
int					print_prefix(t_opt opt, int cond);
void				change_signe(t_opt *opt);
void				print_c(long ret);

int					atoi_base(char *str, char *base);
void				putint_base(int nbr, char *base);

int					szb_ul(t_opt opt, unsigned long base);
int					szb_l(t_opt opt, unsigned long base);
int					szb_s(t_opt opt, unsigned long base);
int					szb_c(t_opt opt, unsigned long base);
int					szb_i(t_opt opt, unsigned long base);

void				bzero_attr(t_opt *opt);
void				bzero_opt(t_opt *opt);
int					print(t_opt opt);
void				putnbr(int nbr, int *ret);

void				putstr_pres(t_opt opt, int *ret, int cond);
int					print_choice(t_opt opt);
void				modify_len(t_opt *opt);
int					get_conv(const char **format, va_list ap, t_opt *opt);
int					print_var(const char **format, va_list ap);

int					print_plus(t_opt opt, int *ret);
int					print_moins(t_opt opt, int *ret);

int					ft_printf(const char *format, ...);
#endif
