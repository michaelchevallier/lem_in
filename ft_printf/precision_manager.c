/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 13:33:39 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/11 15:48:08 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				string_precision_manager(t_var *var)
{
	unsigned char	*tmp;

	tmp = NULL;
	if (var->precision < var->spec_len)
	{
		tmp = var->tmpstr;
		var->tmpstr = ft_ustrsub(var->tmpstr, 0, var->precision);
		if (tmp)
			free(tmp);
	}
}

static void				pm2(t_var *var)
{
	if (var->specifier >= 3 && var->specifier <= 11)
	{
		digit_precision_manager(var);
		if (var->spec_len < var->precision)
			var->spec_len = var->precision;
	}
	if (var->specifier == 0 || var->specifier == 1)
	{
		string_precision_manager(var);
		if (var->spec_len > var->precision)
			var->spec_len = var->precision;
	}
}

void					precision_manager(t_var *var)
{
	unsigned char		*tmp;

	tmp = NULL;
	if (ft_intmaxuatoi(var->tmpstr) < 0)
	{
		if (var->flags[1] == 1 || var->prec_on == 1)
		{
			var->isneg = 1;
			tmp = var->tmpstr;
			var->tmpstr = ft_ustrsub(var->tmpstr, 1, var->spec_len);
			free(tmp);
		}
	}
	if (var->prec_on == 1)
		pm2(var);
	if (var->flags[1] == 0)
		flag_manager(var);
	width_manager(var);
	if (var->flag_mon == 0)
		flag_manager(var);
}
