/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 15:31:51 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/14 14:56:19 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			sharp_manager(t_var *var, unsigned char *str)
{
	if (ft_uintmaxuatoi(var->tmpstr) != 0 ||
			(var->tmpstr[0] >= 97 && var->tmpstr[0] <= 102))
	{
		if (var->specifier == 6 || var->specifier == 7)
		{
			str[0] = '0';
			var->tmpstr = ft_uustrjoin_and_free(str, var->tmpstr, 2);
			var->spec_len++;
		}
		if (var->specifier == 10 || var->specifier == 11)
		{
			str[0] = '0';
			str[1] = 'x';
			if (var->specifier == 11)
				str[1] = 'X';
			var->tmpstr = ft_uustrjoin_and_free(str, var->tmpstr, 2);
			var->spec_len += 2;
		}
	}
}

static void			space_manager(t_var *var, unsigned char *str)
{
	if (var->prec_on == 0)
	{
		if (var->specifier >= 3 && var->specifier <= 5)
		{
			if (ft_uatoi(var->tmpstr) > 0)
			{
				var->tmpstr = ft_uustrjoin_and_free(str, var->tmpstr, 2);
				var->spec_len++;
			}
		}
	}
}

void				flag_manager(t_var *var)
{
	unsigned char	*str;

	str = ft_ustrdup((unsigned char *)"  ");
	str[1] = '\0';
	var->flag_mon = 1;
	if (var->flags[0] == 1)
		sharp_manager(var, str);
	if (var->flags[2] == 1)
		space_manager(var, str);
	if (var->flags[3] == 1)
		if (var->specifier >= 3 && var->specifier <= 5)
		{
			if (ft_intmaxuatoi(var->tmpstr) >= 0 && var->isneg == 0)
			{
				str[0] = '+';
				var->tmpstr = ft_uustrjoin_and_free(str, var->tmpstr, 2);
				var->spec_len++;
			}
		}
	ft_ustrdel(&str);
}
