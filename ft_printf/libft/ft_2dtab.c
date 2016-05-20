/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dtab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:16:08 by mchevall          #+#    #+#             */
/*   Updated: 2015/12/14 17:25:05 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_2dtab(size_t i, size_t j)
{
	size_t		k;
	char		**tab;

	k = 0;
	tab = (char **)ft_memalloc(sizeof(char *) * i);
	while (k < j)
	{
		tab[k] = (char *)ft_memalloc(sizeof(char) * j);
		k++;
	}
	return (tab);
}
