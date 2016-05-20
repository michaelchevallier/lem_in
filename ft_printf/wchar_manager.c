/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 19:05:14 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/11 16:57:20 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			index_define(int binlen)
{
	if (binlen <= 7)
		return (0);
	if (binlen <= 11)
		return (1);
	if (binlen <= 16)
		return (2);
	else
		return (3);
}

static char			*binarymask(t_wchar *wchar)
{
	char		*tab[4];
	char		*new;
	int			mlen;
	int			i;

	tab[0] = "0xxxxxxx";
	tab[1] = "110xxxxx10xxxxxx";
	tab[2] = "1110xxxx10xxxxxx10xxxxxx";
	tab[3] = "11110xxx10xxxxxx10xxxxxx10xxxxxx";
	new = ft_strdup(tab[wchar->index]);
	mlen = ft_strlen(tab[wchar->index]) - 1;
	i = wchar->binlen;
	while (mlen > 0)
	{
		if (tab[wchar->index][mlen] == 'x' && i > 0)
		{
			new[mlen] = wchar->bin[i - 1];
			i--;
		}
		else if (tab[wchar->index][mlen] == 'x' && i == 0)
			new[mlen] = '0';
		mlen--;
	}
	return (new);
}

static void			octaltoint(char *oct, t_wchar *wchar, int index)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 7;
	wchar->wchar[index] = (oct[7] - 48);
	while (oct[i])
	{
		while (k < j)
		{
			if (wchar->tmpresult == 0)
				wchar->tmpresult += 2 * (oct[i] - 48);
			else
				wchar->tmpresult *= 2 * (oct[i] - 48);
			k++;
		}
		wchar->wchar[index] += wchar->tmpresult;
		k = 0;
		wchar->tmpresult = 0;
		i++;
		j--;
	}
	((oct) ? free(oct) : 0);
}

static void			wchar_initializer(t_wchar *wchar, t_var *var)
{
	wchar->bin = ft_itoa_base((wint_t)var->arg, 2);
	wchar->binlen = ft_strlen(wchar->bin);
	wchar->index = index_define(wchar->binlen);
	wchar->wchar = (int *)ft_memalloc(wchar->index + 1);
	wchar->wchar[wchar->index] = -1;
	wchar->tmpresult = 0;
}

t_wchar				*wchar_manager(t_var *var)
{
	t_wchar		*wchar;
	char		*bin;
	int			i;

	wchar = (t_wchar *)ft_memalloc(sizeof(t_wchar));
	wchar_initializer(wchar, var);
	bin = binarymask(wchar);
	i = 0;
	while (i <= wchar->index)
	{
		octaltoint(ft_strsub(bin, (i * 8), 8), wchar, i);
		i++;
	}
	ft_strdel(&bin);
	return (wchar);
}
