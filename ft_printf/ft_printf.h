/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:37:15 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/13 15:07:56 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <locale.h>
# include <wchar.h>
# include "libft/includes/libft.h"
# include <stdarg.h>
# define NB_FLAGS 5
# define NB_SPEC 16
# define J_N_F ft_strjoin_and_free
# define UJ_N_F ft_ustrjoin_and_free
# define UUJ_N_F ft_uustrjoin_and_free
# define FS format_specifier
# define FLAGS "#0 +-"
# define MODIFIER "hljz"
# define SPECIFIER "sSpdDioOuUxXcC%b"

typedef struct			s_var
{
	void				*arg;
	unsigned char		*str;
	unsigned char		*tmpstr;
	char				*format_specifier;
	char				*modifier;
	char				*tmp;
	int					*flags;
	int					counter;
	int					specifier;
	int					width;
	int					error;
	int					prec_on;
	int					precision;
	int					mod_len;
	int					spec_len;
	int					global_count;
	int					isneg;
	int					flag_mon;
}						t_var;

typedef struct			s_wchar
{
	size_t				nbchar;
	char				*bin;
	int					binlen;
	int					index;
	int					*wchar;
	int					tmpresult;
}						t_wchar;

typedef int				(*t_funcs)(t_var *var);

int						ft_printf(const char *format, ...);
int						specifier_finder(const char *format, t_var *var,
int i, va_list ap);
void					format_specifier_manager(t_var *var);
void					var_initializer(t_var *var);
int						spec_s(t_var *var);
int						spec_ls(t_var *var);
int						spec_p(t_var *var);
int						spec_d(t_var *var);
int						spec_ld(t_var *var);
int						spec_i(t_var *var);
int						spec_o(t_var *var);
int						spec_lo(t_var *var);
int						spec_u(t_var *var);
int						spec_lu(t_var *var);
int						spec_x(t_var *var);
int						spec_lx(t_var *var);
int						spec_c(t_var *var);
int						spec_lc(t_var *var);
int						spec_percent(t_var *var);
int						spec_b(t_var *var);
void					ft_putwchar(int *wchar);
t_wchar					*wchar_manager(t_var *var);
t_wchar					*wstr_manager(wchar_t str);
char					*chartostring(int c);
char					*wchartostring(t_wchar *wchar);
void					precision_manager(t_var *var);
void					flag_manager(t_var *var);
void					digit_precision_manager(t_var *var);
void					width_manager(t_var *var);
void					free_all(t_var *var, int n);
void					free_wchar(t_wchar *wchar);
#endif
