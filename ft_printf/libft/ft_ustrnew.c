/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:46:43 by mchevall          #+#    #+#             */
/*   Updated: 2016/03/31 14:46:53 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

unsigned char		*ft_ustrnew(size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(size + 1);
	if (ptr)
	{
		ft_memset(ptr, '\0', size + 1);
		return (ptr);
	}
	return (NULL);
}
