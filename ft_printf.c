/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelsweyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:33:22 by lelsweyr          #+#    #+#             */
/*   Updated: 2020/11/20 11:33:25 by lelsweyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processing.h"

int			ft_printf(char const *s, ...)
{
	t_sign	*st;
	va_list	ap;

	if (!(st = (t_sign *)malloc(sizeof(t_sign))) || !s)
		return (0);
	va_start(ap, s);
	st->re = 0;
	while (*s != 0)
	{
		s += ft_begin(s, st);
		if (*s == 0)
			break ;
		s += ft_flag(s, st);
		s += width(s, st, ap);
		s += accur(s, st, ap);
		s += ft_type(s, st);
		processing(st, ap);
	}
	va_end(ap);
	free(st);
	return (st->re);
}
