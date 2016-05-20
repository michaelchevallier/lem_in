/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:15:37 by mchevall          #+#    #+#             */
/*   Updated: 2015/11/30 19:03:31 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t		s2len;
	size_t		i;
	size_t		j;

	s2len = ft_strlen(s2);
	i = 0;
	j = 0;
	if (s2len == 0)
		return (char *)(s1);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[j])
		{
			while (s1[i + j] == s2[j])
			{
				if (s1[i + j] == s2[j] && j + 1 == s2len)
					return (char *)(&s1[i]);
				j++;
			}
		}
		j = 0;
		i++;
	}
	return (NULL);
}
