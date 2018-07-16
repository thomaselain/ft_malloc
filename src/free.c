/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 20:46:43 by telain            #+#    #+#             */
/*   Updated: 2018/07/16 20:46:46 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		free(void *ptr)
{
	t_zone	*to_free;

	if (!(to_free = find_location(ptr)))
		return ;
	munmap(&to_free, to_free->size);
}

t_zone		*find_location(void *ptr)
{
	if (!(zone = scan_bucket(g_global.tiny))
		&& !(zone = scan_bucket(g_global.small))
		&& !(zone = scan_bucket(g_global.large)))
		return (NULL);
	else
		return (zone);
}

t_bucket	