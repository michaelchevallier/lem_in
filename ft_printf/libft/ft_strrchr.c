/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:47:50 by mchevall          #+#    #+#             */
/*   Updated: 2015/11/30 16:51:10 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen(s);
	while (s[len] != c && len >= 0)
		len--;
	if (s[len] == c)
		return (char *)(&s[len]);
	else
		return (NULL);
}
