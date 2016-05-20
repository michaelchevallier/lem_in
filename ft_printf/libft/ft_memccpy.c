/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:45:50 by mchevall          #+#    #+#             */
/*   Updated: 2015/11/26 17:17:25 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptrsrc;
	unsigned char	*ptrdst;

	i = 0;
	ptrsrc = (unsigned char *)src;
	ptrdst = (unsigned char *)dst;
	while (i < n)
	{
		ft_memcpy(&ptrdst[i], &ptrsrc[i], 1);
		if (ptrsrc[i] == (unsigned char)c)
			return (&ptrdst[i + 1]);
		i++;
	}
	return (NULL);
}
