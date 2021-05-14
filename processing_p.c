/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelsweyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:33:22 by lelsweyr          #+#    #+#             */
/*   Updated: 2020/12/09 19:38:27 by lelsweyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processing.h"

char		*proc_p(char *d, size_t c, t_sign *st)
{
	if (c == 0)
		return (d + 1);
	if (c % 16 < 10)
		*d-- = (c % 16 + 48);
	else
		*d-- = c % 16 + 87;
	return (proc_p(d, c / 16, st));
}

void		proc_pp(t_sign *st, char *a, int len, char *d)
{
	if (st->width < len && st->accur < len)
		case_1p(d, len, st, a);
	else if (st->width >= len && st->accur < len)
		case_2p(d, len, st, a);
	else if (st->width < len && st->accur >= len)
		case_3p(d, len, st, a);
	else if (st->width >= len && st->accur >= len)
		case_4p(d, len, st, a);
	ft_length_p(st, len);
}

void		ft_length_p(t_sign *st, int len)
{
	if (st->width >= st->accur && st->width >= (len + 2))
		st->re += st->width;
	else if (st->accur >= st->width && st->accur >= (len + 2))
		st->re += st->accur + 2;
	else if (st->accur <= (len + 2) && st->width <= (len + 2))
		st->re += (len + 2);
}

int			num_len(size_t arg)
{
	int len;

	len = 0;
	while (arg > 0)
	{
		arg /= 10;
		len++;
	}
	return (len);
}

void		processing_pointer(t_sign *st, size_t arg)
{
	char	*d;
	char	*m;
	int		len;

	len = num_len(arg);
	if (!(d = (char *)malloc((len + 1) * sizeof(char))))
		return ;
	ft_bzero(d, len + 1);
	if (!arg)
	{
		if (!st->point)
		{
			len = 1;
			proc_pp(st, "0x", len, "0");
		}
		else
			proc_pp(st, "0x", len, "");
	}
	else
	{
		m = proc_p(d, arg, st);
		len = ft_strlen(m);
		proc_pp(st, "0x", len, m);
	}
	free(d);
}
