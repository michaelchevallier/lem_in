/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 16:10:56 by mchevall          #+#    #+#             */
/*   Updated: 2016/03/31 16:36:08 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

size_t	ft_wcharlen(const wchar_t *wchar)
{
	const wchar_t *p;

	p = wchar;
	while (*p)
		p++;
	return (p - wchar);
}
