/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:47:29 by mchevall          #+#    #+#             */
/*   Updated: 2015/11/25 15:46:00 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	comp;
	int		i;

	comp = c;
	i = 0;
	if (comp == '\0')
	{
		while (s[i] != comp)
			i++;
	}
	while (s[i] != comp && s[i] != '\0')
		i++;
	if (s[i] == comp)
		return (char *)(&s[i]);
	else
		return (NULL);
}
