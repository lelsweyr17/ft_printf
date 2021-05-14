/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_p2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelsweyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:33:22 by lelsweyr          #+#    #+#             */
/*   Updated: 2020/12/09 19:41:17 by lelsweyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processing.h"

void	case_1p(char *d, int len, t_sign *st, char *a)
{
	int i;

	i = 0;
	while (*a)
		ft_putchar(*a++);
	while (i < len)
		ft_putchar(d[i++]);
}

void	case_2p_1(char *d, int len, t_sign *st, char *a)
{
	int i;

	i = 0;
	while (*a && !st->point)
		ft_putchar(*a++);
	while (i++ < (st->width - len - 2) && !st->point)
		ft_putchar('0');
	i--;
	while (i++ < (st->width - len - 2) && st->point)
		ft_putchar(' ');
	i = 0;
	while (*a && st->point)
		ft_putchar(*a++);
	while (i < len)
		ft_putchar(d[i++]);
}

void	case_2p(char *d, int len, t_sign *st, char *a)
{
	int i;

	i = 0;
	if (st->flag.no)
	{
		while (i++ < (st->width - len - 2))
			ft_putchar(' ');
		i = 0;
		while (*a)
			ft_putchar(*a++);
		while (i < len)
			ft_putchar(d[i++]);
	}
	else if (st->flag.fl_null)
		case_2p_1(d, len, st, a);
	else if (st->flag.fl_minus)
	{
		while (*a)
			ft_putchar(*a++);
		while (i < len)
			ft_putchar(d[i++]);
		while (i++ < (st->width - 2))
			ft_putchar(' ');
	}
}

void	case_3p(char *d, int len, t_sign *st, char *a)
{
	int i;

	i = 0;
	while (*a)
		ft_putchar(*a++);
	while (i++ < (st->accur - len))
		ft_putchar('0');
	i = 0;
	while (i < len)
		ft_putchar(d[i++]);
}

void	case_4p(char *d, int len, t_sign *st, char *a)
{
	int i;

	i = 0;
	while (i++ < (st->width - st->accur - 2) && \
		(st->flag.no || st->flag.fl_null))
		ft_putchar(' ');
	while (*a)
		ft_putchar(*a++);
	i = 0;
	while (i++ < (st->accur - len))
		ft_putchar('0');
	i = 0;
	while (i < len)
		ft_putchar(d[i++]);
	i = 0;
	while (i++ < (st->width - st->accur - 2) && st->flag.fl_minus)
		ft_putchar(' ');
}
