/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_u_x_percent.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelsweyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:33:22 by lelsweyr          #+#    #+#             */
/*   Updated: 2020/12/09 19:46:21 by lelsweyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processing.h"

void		proc_u(char *d, int len, t_sign *st)
{
	if (st->width <= len && st->accur <= len)
		case_1(d, len, st);
	else if (st->width > len && st->accur <= len)
		case_2(st, d, len);
	else if (st->width <= len && st->accur > len)
		case_3(st, d, len);
	else if (st->width > len && st->accur > len)
		case_4(st, d, len);
}

char		*proc_x(char *d, unsigned c, t_sign *st)
{
	if (c == 0)
		return (d + 1);
	if (c % 16 < 10)
		*d-- = (c % 16 + 48);
	else
	{
		if (st->type.x)
			*d-- = c % 16 + 87;
		else
			*d-- = c % 16 + 55;
	}
	return (proc_x(d, c / 16, st));
}

void		processing_u_x(t_sign *st, unsigned c)
{
	int		i;
	char	*d;
	int		len;
	char	*m;

	i = 0;
	d = ft_utoa(c);
	len = ft_strlen(d);
	m = d;
	if (ft_null(st, d, len) == 1)
	{
		free(d);
		return ;
	}
	if (st->type.u)
		proc_u(d, len, st);
	else if (st->type.x || st->type.xx)
	{
		if (c > 0)
			m = proc_x(d + len - 1, c, st);
		len = ft_strlen(m);
		proc_u(m, len, st);
	}
	ft_length(st, len);
	free(d);
}

void		processing_percent(t_sign *st)
{
	int i;

	i = 0;
	if (st->flag.no)
	{
		while (i++ < (st->width - 1))
			ft_putchar(' ');
		ft_putchar('%');
	}
	else if (st->flag.fl_minus)
	{
		ft_putchar('%');
		while (i++ < (st->width - 1))
			ft_putchar(' ');
	}
	else if (st->flag.fl_null)
	{
		while (i++ < (st->width - 1))
			ft_putchar('0');
		ft_putchar('%');
	}
	ft_length(st, 1);
}
