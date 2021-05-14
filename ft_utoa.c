/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelsweyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:08:41 by lelsweyr          #+#    #+#             */
/*   Updated: 2020/12/09 18:12:25 by lelsweyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processing.h"

static void		ft_full(char *nbr, long int count, unsigned nb, int count3)
{
	int			i;
	unsigned	n;

	i = 0;
	n = nb;
	while ((count /= 10) >= 1)
	{
		nbr[i++] = nb / count + 48;
		nb %= count;
	}
	nbr[i] = 0;
}

static int		ft_count(unsigned nb)
{
	int			count;

	count = 1;
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char			*ft_utoa(unsigned n)
{
	char		*nbr;
	unsigned	nb;
	long int	count;
	int			count2;
	int			count3;

	count = 1;
	nb = n;
	count2 = ft_count(n);
	count3 = count2;
	nbr = (char *)malloc((count2 + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	while (count2 > 0)
	{
		count *= 10;
		count2--;
	}
	ft_full(nbr, count, nb, count3);
	return (nbr);
}
