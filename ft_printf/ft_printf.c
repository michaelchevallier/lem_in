/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:09:54 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/13 17:01:32 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		funcs_finder(t_var *var, int specifier)
{
	static const t_funcs	funcs[] = {spec_s, spec_ls, spec_p, spec_d, spec_ld,
		spec_i, spec_o, spec_lo, spec_u, spec_lu, spec_x, spec_lx, spec_c,
		spec_lc, spec_percent, spec_b};

	funcs[specifier](var);
}

static int		percent_found(const char *format, va_list ap, t_var *var, int i)
{
	if (format[i + 1] == '%')
	{
		var->str = UJ_N_F(var->str, ft_strsub(format, i + 1, 1), 0);
		i += 1;
		var->global_count++;
	}
	else
	{
		if ((i = specifier_finder(format, var, i, ap)) == -1)
			return ((var->error = -1));
		format_specifier_manager(var);
		if (var->error == -1)
			return (-1);
		funcs_finder(var, var->specifier);
		if (var->specifier == -1 || var->error == -1)
			return ((var->error = -1));
		var->tmpstr = UJ_N_F(var->tmpstr, var->arg, 0);
		precision_manager(var);
		if (var->tmpstr && var->error == 0)
			var->str = UUJ_N_F(var->str, var->tmpstr, 1);
		var->global_count += var->spec_len;
	}
	return (i);
}

static void		mini_init(t_var *var)
{
	var->str = (unsigned char *)ft_memalloc(sizeof(unsigned char));
	var->error = 0;
	var->global_count = 0;
}

static int		format_manager(const char *format, va_list ap, t_var *var)
{
	int				i;

	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			var->str = UJ_N_F(var->str, ft_strsub(format, i, 1), 0);
			var->global_count += 1;
		}
		else if ((i = percent_found(format, ap, var, i)) == -1)
			return ((var->error = -1));
		i++;
		free_all(var, 0);
	}
	return (i);
}

int				ft_printf(const char *format, ...)
{
	va_list			ap;
	t_var			*var;
	int				j;

	j = 0;
	var = (t_var *)ft_memalloc(sizeof(t_var));
	mini_init(var);
	va_start(ap, format);
	format_manager(format, ap, var);
	if (var->error == 0)
		while (j < var->global_count)
		{
			ft_putchar(var->str[j]);
			j++;
		}
	else
	{
		free_all(var, 1);
		return (-1);
	}
	va_end(ap);
	free_all(var, 1);
	return (var->global_count);
}
