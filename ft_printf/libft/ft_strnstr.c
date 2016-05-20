/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:14:36 by mchevall          #+#    #+#             */
/*   Updated: 2015/12/14 15:26:18 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (s2[i] == '\0')
		return (char *)(s1);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[j] && i < n)
		{
			while (s2[j] && s1[i + j] == s2[j] && (i + j) < (n))
			{
				if (s1[i + j] == s2[j] && j + 1 == ft_strlen(s2))
					return (char *)(&s1[i]);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
