/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_cases2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelsweyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:33:22 by lelsweyr          #+#    #+#             */
/*   Updated: 2020/12/09 18:21:05 by lelsweyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processing.h"

void	case_3(t_sign *st, char *arg, int len)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	if (arg[0] == '-')
	{
		st->re++;
		ft_putchar(arg[flag++]);
	}
	while (i++ < (st->accur - len + flag))
		ft_putchar('0');
	while (flag < len)
		ft_putchar(arg[flag++]);
}

void	case_4_1(t_sign *st, int flag, char *arg, int len)
{
	int i;

	i = 0;
	while (i++ < (st->width - st->accur - flag))
		ft_putchar(' ');
	if (flag == 1)
	{
		ft_putchar('-');
		if (st->accur >= st->width)
			st->re++;
	}
	i = 0;
	while (i++ < (st->accur - len + flag))
		ft_putchar('0');
	while (flag < len)
		ft_putchar(arg[flag++]);
}

void	case_4(t_sign *st, char *arg, int len)
{
	int flag;
	int i;

	flag = 0;
	i = 0;
	if (arg[0] == '-')
		flag = 1;
	if (st->flag.fl_null || st->flag.no)
		case_4_1(st, flag, arg, len);
	else if (st->flag.fl_minus)
	{
		if (arg[i] == '-')
		{
			ft_putchar(arg[i]);
			if (st->accur >= st->width)
				st->re++;
		}
		while (i++ < (st->accur - len + flag))
			ft_putchar('0');
		while (flag < len)
			ft_putchar(arg[flag++]);
		i += (flag - 1);
		while (i++ < st->width)
			ft_putchar(' ');
	}
}
