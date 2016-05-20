/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:47:56 by mchevall          #+#    #+#             */
/*   Updated: 2016/03/31 15:49:03 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	*ft_ustrsub(unsigned char *s, unsigned int start, size_t len)
{
	unsigned char		*str;
	size_t				i;

	if (s == NULL || (int)len < 0)
		return (NULL);
	str = ft_ustrnew(len);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
