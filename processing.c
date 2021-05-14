/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelsweyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:33:22 by lelsweyr          #+#    #+#             */
/*   Updated: 2020/12/09 18:47:35 by lelsweyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processing.h"

int			ft_null(t_sign *st, char *d, int len)
{
	int i;

	i = 0;
	if (d[0] == '0' && !st->point)
	{
		if (st->width != 0 && st->accur)
			return (0);
		else if (st->accur == 0 && st->point)
			return (1);
	}
	else if (d[0] == '0' && st->point && st->accur == 0)
	{
		while (i++ < st->width)
			ft_putchar(' ');
		st->re += (i - 1);
		return (1);
	}
	return (0);
}

void		proc_d_i(char *d, int len, t_sign *st)
{
	if (st->width < len && st->accur < len)
		case_1(d, len, st);
	else if (st->width >= len && st->accur < len)
		case_2(st, d, len);
	else if (st->width < len && st->accur >= len)
		case_3(st, d, len);
	else if (st->width >= len && st->accur >= len)
		case_4(st, d, len);
}

void		ft_length(t_sign *st, int len)
{
	if (st->width >= st->accur && st->width >= len)
		st->re += st->width;
	else if (st->accur >= st->width && st->accur >= len)
		st->re += st->accur;
	else if (st->accur <= len && st->width <= len)
		st->re += len;
}

void		processing_int(t_sign *st, int arg)
{
	char	*d;
	int		len;
	int		i;

	i = 0;
	d = ft_itoa(arg);
	len = ft_strlen(d);
	if (!d)
		return ;
	if (ft_null(st, d, len))
	{
		free(d);
		return ;
	}
	proc_d_i(d, len, st);
	ft_length(st, len);
	free(d);
}

void		processing(t_sign *st, va_list ap)
{
	if (st->type.percent)
		processing_percent(st);
	else if (st->type.i)
		processing_int(st, va_arg(ap, int));
	else if (st->type.u || st->type.x || st->type.xx)
		processing_u_x(st, va_arg(ap, unsigned));
	else if (st->type.c)
		processing_char(st, va_arg(ap, int));
	else if (st->type.s)
		processing_str(st, va_arg(ap, char *));
	else if (st->type.p)
		processing_pointer(st, va_arg(ap, size_t));
}
