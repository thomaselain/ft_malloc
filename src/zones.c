/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zones.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:36:08 by telain            #+#    #+#             */
/*   Updated: 2018/07/09 17:36:09 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

t_zone			*new_zone(size_t size, t_bucket *b)
{
	t_zone	*new;
	t_zone	*tmp;
	size_t	offset;

	tmp = b->zone;
	offset = 0;
	if (tmp)
		offset = tmp->n_bytes;
	while (tmp && tmp->next)
	{
		offset += tmp->next->n_bytes;
		tmp = tmp->next;
	}
	printf("Offset  : %zu\n", offset);
	new = (t_zone*)mmap(&b + offset, sizeof(t_zone), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	new->n_bytes = size;
	new->free = FALSE;
	if (!b->zone)
		b->zone = new;
	else
		tmp->next = new;
	b->remaining -= size;
	b->allocated += size;
	return (new);
}