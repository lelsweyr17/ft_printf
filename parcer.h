/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelsweyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:33:22 by lelsweyr          #+#    #+#             */
/*   Updated: 2020/12/09 20:19:40 by lelsweyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCER_H
# define PARCER_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

typedef	struct	s_flag
{
	int fl_null;
	int fl_minus;
	int no;
}				t_flag;

typedef struct	s_type
{
	int i;
	int u;
	int c;
	int s;
	int p;
	int x;
	int xx;
	int percent;
}				t_type;

typedef struct	s_sign
{
	t_flag		flag;
	int			width;
	int			accur;
	int			point;
	int			re;
	t_type		type;
}				t_sign;

int				ft_printf(char const *s, ...);
void			ft_putchar(char c);
void			ft_list_null(t_sign *st);
int				ft_flag(char const *s, t_sign *st);
int				ft_begin(char const *s, t_sign *st);
int				width(char const *s, t_sign *st, va_list ap);
int				accur(char const *s, t_sign *st, va_list ap);
int				ft_type(char const *s, t_sign *st);
int				ast(int c, t_sign *st, char const *s);

#endif
