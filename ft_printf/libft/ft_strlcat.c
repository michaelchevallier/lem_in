/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:14:23 by mchevall          #+#    #+#             */
/*   Updated: 2015/12/08 10:46:45 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char			*ptrdst;
	const char		*ptrsrc;
	size_t			n;
	size_t			len;

	ptrdst = dst;
	ptrsrc = src;
	n = size;
	while (n-- != 0 && *ptrdst != '\0')
		ptrdst++;
	len = ptrdst - dst;
	n = size - len;
	if (n == 0)
		return (len + ft_strlen(ptrsrc));
	while (*ptrsrc != '\0')
	{
		if (n != 1)
		{
			*ptrdst++ = *ptrsrc;
			n--;
		}
		ptrsrc++;
	}
	*ptrdst = '\0';
	return (len + (ptrsrc - src));
}
