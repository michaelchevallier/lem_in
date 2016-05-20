/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 13:34:16 by mchevall          #+#    #+#             */
/*   Updated: 2016/05/18 13:22:29 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**ft_realloc(char **tab)
{
	char		**realloced;
	int			i;
	static int	j = 0;

	i = 0;
	j++;
	realloced = (char **)ft_memalloc(sizeof(char *) * ((1 + j) * 1024));
	while (i <= (j * 1024 - 1))
	{
		realloced[i] = ft_strdup(tab[i]);
		ft_printf("i:%d\n",i);
		free(tab[i]);
		i++;
	}
	free(tab);
	return (realloced);
}
