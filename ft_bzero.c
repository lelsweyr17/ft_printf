/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelsweyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:44:16 by lelsweyr          #+#    #+#             */
/*   Updated: 2020/12/09 18:11:44 by lelsweyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processing.h"

char				*ft_bzero(char *s, int n)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (i < n)
		s[i++] = '\0';
	return (s);
}
