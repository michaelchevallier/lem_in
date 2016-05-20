/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uustrcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:41:05 by mchevall          #+#    #+#             */
/*   Updated: 2016/03/31 14:50:08 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char		*ft_uustrcat(unsigned char *s1, unsigned char *s2)
{
	size_t		s1_len;
	size_t		s2_len;
	size_t		total_len;
	size_t		i;

	s1_len = ft_ustrlen(s1);
	s2_len = ft_ustrlen(s2);
	total_len = s1_len + s2_len;
	i = 0;
	while (s1_len < total_len + 1)
	{
		s1[s1_len] = s2[i];
		s1_len++;
		i++;
	}
	return (s1);
}
