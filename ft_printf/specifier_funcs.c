/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 09:55:03 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/13 14:55:13 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			spec_s(t_var *var)
{
	if (var->arg == NULL)
	{
		var->arg = ft_strdup("(null)");
		return ((var->spec_len = 6));
	}
	else if (var->mod_len == 0)
	{
		var->arg = ft_strdup(var->arg);
		var->spec_len = ft_strlen(var->arg);
	}
	else if (var->mod_len == 1 && var->modifier[0] == 'l')
	{
		var->mod_len = 0;
		spec_ls(var);
	}
	else
		return ((var->error = -1));
	return (0);
}

int			spec_ls(t_var *var)
{
	t_wchar				*wchar;
	wchar_t				*str;
	unsigned char		*str2;
	size_t				i;

	str = NULL;
	wchar = NULL;
	str2 = ft_ustrdup((unsigned char *)"");
	i = -1;
	if (var->arg == NULL)
		spec_s(var);
	else
	{
		str = (wchar_t *)var->arg;
		while (++i < ft_wcharlen(str))
		{
			wchar = wstr_manager(str[i]);
			str2 = UJ_N_F(str2, wchartostring(wchar), 0);
			if (wchar)
				free_wchar(wchar);
		}
		var->arg = str2;
		var->spec_len = ft_ustrlen(str2);
	}
	return (0);
}

int			spec_p(t_var *var)
{
	char				*str;

	str = ft_itoa_baseuint((uintmax_t)var->arg, 16);
	var->arg = ft_strjoin("0x", str);
	var->spec_len = ft_strlen(var->arg);
	ft_strdel(&str);
	return (0);
}

int			spec_d2(t_var *var)
{
	if (var->modifier[0] == 'h')
		var->arg = ft_itoa((short int)var->arg);
	else if (var->modifier[0] == 'l')
		var->arg = ft_itoa_base((long int)var->arg, 10);
	else if (var->modifier[0] == 'j')
		var->arg = ft_itoa_base((intmax_t)var->arg, 10);
	else if (var->modifier[0] == 'z')
		var->arg = ft_itoa_base((size_t)var->arg, 10);
	else
		return (-1);
	return (0);
}

int			spec_d(t_var *var)
{
	if (var->mod_len == 2)
	{
		if (ft_strcmp(var->modifier, "hh") == 0)
			var->arg = ft_itoa_base((signed char)var->arg, 10);
		else if (ft_strcmp(var->modifier, "ll") == 0)
			var->arg = ft_itoa_base((long long)var->arg, 10);
		else
			return ((var->error = -1));
	}
	else if (var->mod_len == 1)
	{
		if (spec_d2(var) == -1)
			return ((var->error = -1));
	}
	else if (var->mod_len == 0)
		var->arg = ft_itoa((int)var->arg);
	else
		return ((var->error = -1));
	return ((var->spec_len = ft_strlen(var->arg)));
}
