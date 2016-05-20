/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:22:07 by mchevall          #+#    #+#             */
/*   Updated: 2016/01/21 16:47:07 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t			ft_size(int n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int				ft_isneg(int n)
{
	int				neg;

	neg = 0;
	if (n < 0)
		neg = 1;
	return (neg);
}

static char				*calc(int n, int i, char *chain)
{
	int				isneg;
	unsigned int	nb;

	isneg = ft_isneg(n);
	if (isneg == 1)
		nb = n * -1;
	else
		nb = n;
	while (nb > 0)
	{
		chain[i] = ((nb % 10 + 48));
		nb = nb / 10;
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

char					*ft_itoa(int n)
{
	char			*chain;
	int				i;
	int				len;

	i = 0;
	len = ft_size(n);
	chain = (char *)ft_memalloc(sizeof(char) * len);
	if (!chain)
		return (NULL);
	if (n == 0)
	{
		chain[i] = 48;
		chain[i + 1] = '\0';
		return (&chain[i]);
	}
	chain = calc(n, i, chain);
	return (chain);
}
