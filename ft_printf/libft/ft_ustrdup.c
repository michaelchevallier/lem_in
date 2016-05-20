/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 15:33:33 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/12 15:38:23 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

unsigned char	*ft_ustrdup(unsigned char *s1)
{
	unsigned char	*dup;
	int				length;
	int				i;

	length = ft_ustrlen(s1);
	i = 0;
	dup = (unsigned char *)malloc(sizeof(unsigned char) * (length + 1));
	if (!dup)
		return (NULL);
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
