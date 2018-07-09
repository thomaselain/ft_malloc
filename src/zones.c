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

void		new_zone(size_t size, t_bucket *b)
{
	t_zone	*new;
	t_zone	*tmp;
	size_t	offset;

	offset = 0;
	tmp = b->zones;
	while (tmp)
	{
		offset += tmp->n_bytes;
		tmp = tmp->next;
	}
	new = mmap(&(bucket + offset), sizeof(t_zone), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	new->n_bytes = size;
	new->free = FALSE;
	tmp->next = new;
	b->new_ptr = new;
	return (new);
}