/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenwords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 14:24:47 by mchevall          #+#    #+#             */
/*   Updated: 2016/02/16 16:49:45 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_lenwords(const char *s, char c, int word)
{
	int i;
	int j;

	i = 0;
	while (word != 0)
	{
		j = 0;
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
		}
		if (s[i] != c)
		{
			while (s[i] != c)
			{
				i++;
				j++;
			}
		}
		word--;
	}
	return (j);
}
