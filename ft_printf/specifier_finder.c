/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_finder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:20:28 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/12 19:37:09 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		sf2(const char *format, t_var *var, int j)
{
	if (var->tmp)
		free(var->tmp);
	var->tmp = ft_strsub(format, j, 1);
	var->FS = J_N_F(var->FS, var->tmp, 1);
}

int			specifier_finder(const char *format, t_var *var, int i, va_list ap)
{
	size_t				j;
	size_t				k;

	j = i;
	k = 0;
	var_initializer(var);
	while ((format[j] != SPECIFIER[k]) && format[i])
	{
		var->arg = va_arg(ap, void *);
		while (format[j] != SPECIFIER[k] &&
				format[i] && var->specifier == -1)
		{
			k = 0;
			j++;
			while (format[j] != SPECIFIER[k] && SPECIFIER[k])
				k++;
			if (SPECIFIER[k] == format[j] && k < ft_strlen(SPECIFIER))
				var->specifier = k;
			if (k == ft_strlen(SPECIFIER))
				sf2(format, var, j);
		}
	}
	i = j;
	ft_strdel(&var->tmp);
	return (((k >= NB_SPEC) ? -1 : i));
}
