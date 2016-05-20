/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_funcs3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:08:00 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/13 14:53:09 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				spec_u2(t_var *var)
{
	if (var->modifier[0] == 'h')
		var->arg = ft_itoa_baseuint((unsigned short int)var->arg, 10);
	else if (var->modifier[0] == 'l')
		var->arg = ft_itoa_baseuint((unsigned long int)var->arg, 10);
	else if (var->modifier[0] == 'j')
		var->arg = ft_itoa_baseuint((uintmax_t)var->arg, 10);
	else if (var->modifier[0] == 'z')
		var->arg = ft_itoa_baseuint((size_t)var->arg, 10);
	else
		return (-1);
	return (0);
}

int				spec_u(t_var *var)
{
	if (var->mod_len == 2)
	{
		if (ft_strcmp(var->modifier, "hh") == 0)
			var->arg = ft_itoa_baseuint((unsigned char)var->arg, 10);
		else if (ft_strcmp(var->modifier, "ll") == 0)
			var->arg = ft_itoa_baseuint((unsigned long long int)var->arg, 10);
		else
			return ((var->error = -1));
	}
	else if (var->mod_len == 1)
	{
		if (spec_u2(var) == -1)
			return ((var->error = -1));
	}
	else if (var->mod_len == 0)
		var->arg = ft_itoa_baseuint((unsigned int)var->arg, 10);
	else
		return ((var->error = -1));
	return ((var->spec_len = ft_strlen(var->arg)));
}

int				spec_lu(t_var *var)
{
	var->arg = ft_itoa_baseuint((unsigned long int)var->arg, 10);
	var->spec_len = ft_strlen(var->arg);
	return (0);
}

int				spec_x2(t_var *var)
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

int				spec_x(t_var *var)
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
		if (spec_x2(var) == -1)
			return ((var->error = -1));
	}
	else if (var->mod_len == 0)
		var->arg = ft_itoa_baseuint((unsigned int)var->arg, 16);
	else
		return ((var->error = -1));
	return ((var->spec_len = ft_strlen(var->arg)));
}
