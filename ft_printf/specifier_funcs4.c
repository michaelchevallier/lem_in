/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_funcs4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 14:37:13 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/13 17:14:02 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				spec_lx2(t_var *var)
{
	if (var->modifier[0] == 'h')
		var->arg = ft_itoa_baseuint((unsigned short int)var->arg, 16);
	else if (var->modifier[0] == 'l')
		var->arg = ft_itoa_baseuint((unsigned long int)var->arg, 16);
	else if (var->modifier[0] == 'j')
		var->arg = ft_itoa_baseuint((uintmax_t)var->arg, 16);
	else if (var->modifier[0] == 'z')
		var->arg = ft_itoa_baseuint((size_t)var->arg, 16);
	else
		return (-1);
	return (0);
}

int				spec_lx(t_var *var)
{
	if (var->mod_len == 2)
	{
		if (ft_strcmp(var->modifier, "hh") == 0)
			var->arg = ft_itoa_baseuint((unsigned char)var->arg, 16);
		else if (ft_strcmp(var->modifier, "ll") == 0)
			var->arg = ft_itoa_baseuint((unsigned long long int)var->arg, 16);
		else
			return ((var->error = -1));
	}
	else if (var->mod_len == 1)
	{
		if (spec_lx2(var) == -1)
			return ((var->error = -1));
	}
	else if (var->mod_len == 0 && var->error != -1)
		var->arg = ft_itoa_baseuint((unsigned int)var->arg, 16);
	else
		return ((var->error = -1));
	var->arg = ft_stringupper(var->arg);
	return ((var->spec_len = ft_strlen(var->arg)));
}

int				spec_c(t_var *var)
{
	var->spec_len = 1;
	if (var->mod_len == 0)
		var->arg = (char *)chartostring((int)var->arg);
	else if (var->mod_len == 1 && var->modifier[0] == 'l')
	{
		var->mod_len = 0;
		spec_lc(var);
	}
	else
		return ((var->error = -1));
	return (0);
}

int				spec_lc(t_var *var)
{
	t_wchar		*wchar;

	wchar = NULL;
	wchar = wchar_manager(var);
	var->arg = wchartostring(wchar);
	var->spec_len = ft_strlen(var->arg);
	if (var->spec_len == 0)
		var->spec_len = 1;
	if (wchar)
		free_wchar(wchar);
	return (0);
}

int				spec_percent(t_var *var)
{
	var->arg = chartostring((int)'%');
	var->spec_len = 1;
	return (0);
}
