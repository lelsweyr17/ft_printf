/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_char_str2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelsweyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:33:22 by lelsweyr          #+#    #+#             */
/*   Updated: 2020/12/09 19:08:28 by lelsweyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processing.h"

void	case_str3_1(t_sign *st, char *arg, int len)
{
	int i;

	i = 0;
	if (st->flag.no || st->flag.fl_null)
	{
		while (i++ < (st->width - st->accur) && st->flag.no)
			ft_putchar(' ');
		i--;
		while (i++ < (st->width - st->accur) && st->flag.fl_null)
			ft_putchar('0');
		st->re += (i - 1);
		i = 0;
		while (i < st->accur)
			ft_putchar(arg[i++]);
		st->re += i;
	}
	else if (st->flag.fl_minus)
	{
		while (i < st->accur)
			ft_putchar(arg[i++]);
		while (i++ < st->width)
			ft_putchar(' ');
		st->re += (i - 1);
	}
}

void	case_str3_2(t_sign *st, char *arg, int len)
{
	int i;

	i = 0;
	if (st->point && !st->accur && st->width)
	{
		while (i++ < st->width)
			ft_putchar(' ');
		st->re += (i - 1);
	}
	else
	{
		while (i < len)
			ft_putchar(arg[i++]);
		while (i++ < st->width)
			ft_putchar(' ');
		st->re += (i - 1);
	}
}

void	case_str3(t_sign *st, char *arg, int len)
{
	int i;

	i = 0;
	if (st->point && st->accur > 0)
		case_str3_1(st, arg, len);
	else if (st->flag.no || st->flag.fl_null)
	{
		while (i++ < (st->width - len) && st->flag.no)
			ft_putchar(' ');
		i--;
		while (i++ < (st->width - len) && st->flag.fl_null)
			ft_putchar('0');
		st->re += (i - 1);
		i = 0;
		while (i++ < len && st->accur == 0 && st->point)
			ft_putchar(' ');
		i--;
		while (i < len)
			ft_putchar(arg[i++]);
		st->re += i;
	}
	else if (st->flag.fl_minus)
		case_str3_2(st, arg, len);
}

void	case_str4(t_sign *st, char *arg, int len)
{
	int i;

	i = 0;
	if (st->flag.no || st->flag.fl_null)
	{
		while (i++ < (st->width - len) && st->flag.no)
			ft_putchar(' ');
		i--;
		while (i++ < (st->width - len) && st->flag.fl_null)
			ft_putchar('0');
		st->re += (i - 1);
		i = 0;
		while (i < len)
			ft_putchar(arg[i++]);
		st->re += i;
	}
	else if (st->flag.fl_minus)
	{
		while (i < len)
			ft_putchar(arg[i++]);
		while (i++ < st->width)
			ft_putchar(' ');
		st->re += (i - 1);
	}
}
