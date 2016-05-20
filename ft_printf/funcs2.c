/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:37:55 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/05 16:28:06 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*chartostring(int c)
{
	char		*str;

	str = (char *)ft_memalloc(sizeof(char) * 2);
	str[1] = '\0';
	str[0] = (char)c;
	return (str);
}

char			*wchartostring(t_wchar *wchar)
{
	char		*str;
	int			i;

	i = 0;
	str = (char *)ft_memalloc(sizeof(char) * wchar->index + 1);
	while (i <= wchar->index)
	{
		str[i] = (wchar_t)wchar->wchar[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void			ft_putwchar(int *wchar)
{
	int		i;

	i = 0;
	while (wchar[i] != -1)
	{
		write(1, &(wchar[i]), 1);
		i++;
	}
	if (wchar)
		free(wchar);
}
