/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 13:35:02 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/12 20:06:01 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					var_initializer(t_var *var)
{
	var->arg = NULL;
	var->counter = 0;
	if (var->tmp)
		free(var->tmp);
	var->tmp = (char *)ft_memalloc(sizeof(char));
	var->tmpstr = (unsigned char *)ft_memalloc(sizeof(unsigned char));
	if (var->format_specifier)
		free(var->format_specifier);
	var->format_specifier = (char *)ft_memalloc(sizeof(char));
	var->specifier = -1;
	if (var->modifier)
		free(var->modifier);
	var->modifier = (char *)ft_memalloc(sizeof(char));
	if (var->flags)
		free(var->flags);
	var->flags = (int *)ft_memalloc(sizeof(int) * NB_FLAGS + 1);
	var->flags[NB_FLAGS] = -1;
	var->width = -1;
	var->precision = -1;
	var->mod_len = 0;
	var->spec_len = 0;
	var->isneg = 0;
	var->flag_mon = 0;
}

void					free_all(t_var *var, int n)
{
	if (var->tmpstr)
		ft_ustrdel(&var->tmpstr);
	if (var->modifier)
		ft_strdel(&var->modifier);
	if (var->FS)
		ft_strdel(&var->FS);
	if (var->tmp)
		ft_strdel(&var->tmp);
	if (n >= 1)
	{
		if (var->str)
			ft_ustrdel(&var->str);
		if (var->flags)
			free(var->flags);
		if (var)
			free(var);
	}
}

void					free_wchar(t_wchar *wchar)
{
	if (wchar->bin)
		ft_strdel(&wchar->bin);
	if (wchar->wchar)
		free(wchar->wchar);
	free(wchar);
}

static void				dpm2(t_var *var, int diff, unsigned char *str)
{
	diff = var->precision - var->spec_len;
	while (diff > 0)
	{
		var->tmpstr = ft_uustrjoin_and_free(str, var->tmpstr, 2);
		diff--;
	}
}

void					digit_precision_manager(t_var *var)
{
	int				diff;
	unsigned char	*str;

	str = ft_ustrdup((unsigned char *)"0");
	diff = 0;
	if (var->isneg == 1)
		var->precision++;
	if (var->precision == 0 && ft_intmaxuatoi(var->tmpstr) == 0)
	{
		if ((var->specifier == 6 || var->specifier == 7) && var->flags[0] == 1)
			return ;
		var->tmpstr = ft_memset(var->tmpstr, '\0', var->spec_len);
		var->spec_len = 0;
	}
	else if (var->precision > var->spec_len)
		dpm2(var, diff, str);
	if (var->precision < var->width && var->isneg == 1)
	{
		str[0] = '-';
		var->tmpstr = ft_uustrjoin_and_free(str, var->tmpstr, 2);
		var->isneg = 0;
	}
	ft_ustrdel(&str);
}
