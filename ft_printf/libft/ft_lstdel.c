/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:08:16 by mchevall          #+#    #+#             */
/*   Updated: 2015/12/08 18:50:57 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*next;
	t_list		*temp;

	if (alst)
	{
		next = *alst;
		while (next)
		{
			if (del)
				del(next->content, (*next).content_size);
			temp = next->next;
			free(next);
			next = temp;
		}
		*alst = NULL;
	}
}
