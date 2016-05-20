/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_baseuint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 13:05:54 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/07 18:58:14 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t			ft_size(uintmax_t n, int base)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / base;
		i++;
	}
	return (i);
}

static char				*calc(uintmax_t n, int i, char *chain, int base)
{
	uintmax_t		nb;

	nb = n;
	while (nb > 0)
	{
		if (base >= 10 && nb % base >= 10)
			chain[i] = ((nb % base - 10 + 97));
		else
			chain[i] = ((nb % base + 48));
		nb = nb / base;
		i++;
	}
	chain[i] = '\0';
	ft_strrev(chain);
	return (chain);
}

char					*ft_itoa_baseuint(uintmax_t n, int base)
{
	char			*chain;
	int				i;
	int				len;

	i = 0;
	len = ft_size(n, base);
	chain = (char *)ft_memalloc(sizeof(char) * len);
	if (!chain)
		return (NULL);
	if (n == 0)
	{
		chain[i] = 48;
		chain[i + 1] = '\0';
		return (&chain[i]);
	}
	chain = calc(n, i, chain, base);
	return (chain);
}
