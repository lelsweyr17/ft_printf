/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_cases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelsweyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:33:22 by lelsweyr          #+#    #+#             */
/*   Updated: 2020/12/09 18:17:04 by lelsweyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processing.h"

void	case_1(char *arg, int len, t_sign *st)
{
	int i;

	i = 0;
	while (i < len)
		ft_putchar(arg[i++]);
}

void	case_2_2(t_sign *st, char *arg, int len, int flag)
{
	int i;

	i = 0;
	while (i++ < (st->width - len) && st->point)
		ft_putchar(' ');
	i--;
	if (!st->point && flag == 1)
		ft_putchar('-');
	while (i++ < (st->width - len) && !st->point)
		ft_putchar('0');
	i = ((!st->point && flag == 1) ? 1 : 0);
	while (i < len)
		ft_putchar(arg[i++]);
}

void	case_2_1(t_sign *st, char *arg, int len)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	if (arg[0] == '-')
		flag = 1;
	if (st->accur < 0)
	{
		if (flag == 1)
			ft_putchar('-');
		while (i++ < (st->width - len))
			ft_putchar('0');
		i = flag;
		while (i < len)
			ft_putchar(arg[i++]);
	}
	else
		case_2_2(st, arg, len, flag);
}

void	case_2(t_sign *st, char *arg, int len)
{
	int i;
	int flag;

	i = 0;
	flag = ((arg[i] == '-') ? 1 : 0);
	if (st->flag.fl_null)
		case_2_1(st, arg, len);
	else if (st->flag.no)
	{
		while (i++ < (st->width - len))
			ft_putchar(' ');
		i = 0;
		while (i < len)
			ft_putchar(arg[i++]);
	}
	else if (st->flag.fl_minus)
	{
		while (i < len)
			ft_putchar(arg[i++]);
		while (i++ < st->width)
			ft_putchar(' ');
	}
}
