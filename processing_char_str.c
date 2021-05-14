/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_char_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelsweyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:33:22 by lelsweyr          #+#    #+#             */
/*   Updated: 2020/12/09 19:03:14 by lelsweyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processing.h"

void	processing_char(t_sign *st, char arg)
{
	int i;
	int l;

	i = 0;
	l = 1;
	if (st->flag.no)
	{
		while (i++ < (st->width - l))
			ft_putchar(' ');
		ft_putchar(arg);
	}
	else if (st->flag.fl_minus)
	{
		ft_putchar(arg);
		while (i++ < (st->width - l))
			ft_putchar(' ');
	}
	else if (st->flag.fl_null)
	{
		while (i++ < (st->width - l))
			ft_putchar('0');
		ft_putchar(arg);
	}
	ft_length(st, 1);
}

void	case_str1_1(t_sign *st, char *arg, int len)
{
	int i;

	i = 0;
	if (st->accur < 0)
		while (i < len)
			ft_putchar(arg[i++]);
	while (i++ < (st->width - st->accur) && st->flag.no && \
			st->point && st->accur > 0)
		ft_putchar(' ');
	st->re += (i - 1);
}

void	case_str1(t_sign *st, char *arg, int len)
{
	int i;

	i = 0;
	case_str1_1(st, arg, len);
	while (i < st->accur && st->point)
		ft_putchar(arg[i++]);
	while (i < len && !st->point)
		ft_putchar(arg[i++]);
	if (st->point && !st->accur && st->width)
	{
		while (i++ < st->width)
			if (st->flag.fl_null)
				ft_putchar('0');
			else
				ft_putchar(' ');
		st->re += (i - 1);
	}
	else
	{
		while (i++ < st->width && st->flag.fl_minus && st->accur > 0)
			ft_putchar(' ');
		st->re += (i - 1);
	}
}

void	case_str2(t_sign *st, char *arg, int len)
{
	int i;

	i = 0;
	while (i < len)
		ft_putchar(arg[i++]);
	st->re += i;
}

void	processing_str(t_sign *st, char *arg)
{
	int i;
	int len;

	i = 0;
	if (!arg)
		arg = "(null)";
	len = ft_strlen(arg);
	if (st->width <= len && st->accur <= len)
		case_str1(st, arg, len);
	else if (st->width <= len && st->accur > len)
		case_str2(st, arg, len);
	else if (st->width > len && st->accur <= len)
		case_str3(st, arg, len);
	else if (st->width > len && st->accur > len)
		case_str4(st, arg, len);
}
