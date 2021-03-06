/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:19:47 by ukim              #+#    #+#             */
/*   Updated: 2020/11/28 12:26:33 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct	s_flags
{
	int			minus;
	int			zero;
	int			width;
	int			precision;
	int			dot;
	int			wf;
	int			pf;
}				t_flags;

extern int		g_len;
extern char		*g_base_10;
extern char		*g_base_x;
extern char		*g_base_xx;

int				ft_printf(const char *format, ...);
int				ft_print_c(t_flags *flag, va_list ap);
int				ft_print_digit(t_flags *flag, va_list ap);
int				ft_print_str(t_flags *flag, va_list ap);
int				ft_print_point(t_flags *flag, va_list ap);
int				ft_print_ux(t_flags *flag, va_list ap, char *base);
int				ft_print_percent(t_flags *flag);

void			add_zero(char **istr, int minus, t_flags *fg);
char			*ft_free_strjoin(char *s1, char *s2);
char			*init_c_malloc(char c, int i);
int				str_print_minus(t_flags *flag, char *str, char c);

char			*ft_left_strcat(char *str, char c, int width);
char			*ft_right_strcat(char *str, char c, int width);
void			ft_putstr(char *str);
int				ull_length(unsigned long long ull, int base);

char			is_option(char *fm);
void			init_flag(t_flags *tf);
void			set_flag(t_flags *fg, char **fm, va_list ap);

#endif
