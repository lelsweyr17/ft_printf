/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelsweyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:33:22 by lelsweyr          #+#    #+#             */
/*   Updated: 2020/12/09 18:26:44 by lelsweyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processing.h"

int		ft_flag(char const *s, t_sign *st)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] == '-' || s[i] == '0')
	{
		if (s[i] == '-' && !st->flag.fl_minus)
			st->flag.fl_minus = 1;
		else if (s[i] == '0' && !st->flag.fl_null)
			st->flag.fl_null = 1;
		i++;
	}
	if (st->flag.fl_minus == 1 && st->flag.fl_null == 1)
		st->flag.fl_null = 0;
	if (st->flag.fl_minus == 0 && st->flag.fl_null == 0)
		st->flag.no = 1;
	return (i);
}

int		width(char const *s, t_sign *st, va_list ap)
{
	int i;
	int res;
	int count;

	i = 0;
	res = 0;
	count = 1;
	if (!s)
		return (0);
	if (s[i] == '*' && s[i + 1] != '*')
		i += ast(va_arg(ap, int), st, s);
	else
	{
		while (s[i] >= '0' && s[i] <= '9')
		{
			res = res * count + (s[i++] - 48);
			count = 10;
		}
		st->width = res;
	}
	return (i);
}

int		accur(char const *s, t_sign *st, va_list ap)
{
	int i;
	int bot;
	int count;

	i = 0;
	count = 0;
	bot = 0;
	if (!s || s[i] != '.')
		return (0);
	st->point = ((*s == '.') ? 1 : 0);
	if (s[i + 1] == '*' && s[i + 2] != '*')
		i += ast(va_arg(ap, int), st, s);
	else
	{
		i++;
		if (s[1] == '-')
			i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			bot = bot * count + (s[i++] - 48);
			count = 10;
		}
		st->accur = bot;
	}
	return (i);
}

int		ft_type(char const *s, t_sign *st)
{
	int i;

	i = 0;
	if (s[i] == 'd' || s[i] == 'i')
		st->type.i = 1;
	else if (s[i] == 'u')
		st->type.u = 1;
	else if (s[i] == 'c')
		st->type.c = 1;
	else if (s[i] == 's')
		st->type.s = 1;
	else if (s[i] == 'p')
		st->type.p = 1;
	else if (s[i] == 'x')
		st->type.x = 1;
	else if (s[i] == 'X')
		st->type.xx = 1;
	else if (s[i] == '%')
		st->type.percent = 1;
	else
		return (0);
	return (i + 1);
}
