/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:11:24 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/04 19:48:44 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t			ft_size(intmax_t n, int base)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n = n / base;
		i++;
	}
	return (i);
}

static int				ft_isneg(intmax_t n)
{
	int				neg;

	neg = 0;
	if (n < 0)
		neg = 1;
	return (neg);
}

static char				*calc(intmax_t n, int i, char *chain, int base)
{
	int				isneg;
	uintmax_t		nb;

	isneg = ft_isneg(n);
	if (isneg == 1)
		nb = n * -1;
	else
		nb = n;
	while (nb > 0)
	{
		if (nb % base > 10)
			chain[i] = ((nb % base - 10 + 97));
		else
			chain[i] = ((nb % base + 48));
		nb = nb / base;
		i++;
	}
	if (isneg == 1)
	{
		chain[i] = '-';
		i++;
	}
	chain[i] = '\0';
	ft_strrev(chain);
	return (chain);
}

char					*ft_itoa_base(intmax_t n, size_t base)
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
