/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelsweyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:33:22 by lelsweyr          #+#    #+#             */
/*   Updated: 2020/12/09 18:30:28 by lelsweyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processing.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_begin(char const *s, t_sign *st)
{
	int i;

	i = 0;
	ft_list_null(st);
	while (s[i] != '%' && s[i] != 0)
		ft_putchar(s[i++]);
	st->re += i;
	if (s[i] == '%')
		i++;
	return (i);
}

int		ast(int c, t_sign *st, char const *s)
{
	st->point = ((*s == '.') ? 1 : 0);
	if (!st->point)
	{
		if (c < 0)
		{
			st->flag.fl_minus = 1;
			st->flag.fl_null = 0;
			st->flag.no = 0;
			c = -c;
		}
		st->width = c;
		return (1);
	}
	else
	{
		st->accur = c;
		return (2);
	}
	return (1);
}

void	ft_list_null(t_sign *st)
{
	st->flag.fl_minus = 0;
	st->flag.fl_null = 0;
	st->flag.no = 0;
	st->accur = 0;
	st->width = 0;
	st->type.u = 0;
	st->type.c = 0;
	st->type.i = 0;
	st->type.p = 0;
	st->type.percent = 0;
	st->type.s = 0;
	st->type.x = 0;
	st->type.xx = 0;
	st->point = 0;
}
