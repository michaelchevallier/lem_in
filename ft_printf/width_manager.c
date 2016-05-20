/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:44:29 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/13 17:14:54 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				wm2(t_var *var, size_t diff, unsigned char *str)
{
	if (var->isneg == 1 && var->flags[1] == 1 && var->flags[3] == 1)
		var->width++;
	diff = var->width - var->spec_len;
	while (diff > 0)
	{
		if (var->flags[4] == 1)
			var->tmpstr = ft_uustrjoin_and_free(var->tmpstr, str, 1);
		else
			var->tmpstr = ft_uustrjoin_and_free(str, var->tmpstr, 2);
		diff--;
	}
	var->spec_len = var->width;
	if (var->flags[2] == 1)
		var->tmpstr[0] = ' ';
}

void					width_manager(t_var *var)
{
	size_t			diff;
	unsigned char	*str;

	str = ft_ustrdup((unsigned char *)" ");
	diff = 0;
	if (var->flags[1] == 1)
		str[0] = '0';
	if (var->flags[3] == 1 && ft_intmaxuatoi(var->tmpstr) >= 0 &&
			var->prec_on == 0)
		var->width--;
	if (var->flags[0] == 1 && var->flags[1] == 1)
	{
		if ((var->specifier == 6 || var->specifier == 7) &&
				ft_intmaxuatoi(var->tmpstr) != 0)
			var->width -= 1;
		else if ((var->specifier == 10 || var->specifier == 11) &&
				ft_intmaxuatoi(var->tmpstr) != 0)
			var->width -= 2;
	}
	if (var->width > var->spec_len)
		wm2(var, diff, str);
	str[0] = '-';
	if (var->isneg == 1)
		var->tmpstr = ft_uustrjoin_and_free(str, var->tmpstr, 2);
	ft_ustrdel(&str);
}
