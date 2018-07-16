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

void			print_zones(t_bucket *b)
{
	t_zone		*tmp;

	tmp = b->zone;
	while (tmp)
	{
		print_address_hex(tmp);
		ft_putstr(" - ");
		print_address_hex((void*)((size_t)tmp + tmp->n_bytes));
		ft_putstr(" : ");
		ft_putnbr(tmp->n_bytes);
		ft_putstr(" bytes\n");
		tmp = tmp->next;
	}
}

t_zone			*new_zone(size_t size, void **b)
{
	t_zone		*new;
	t_bucket	*b_start;

	new = *b;
	b_start = *b;
	*b += sizeof(t_bucket) + sizeof(t_zone);

	new->n_bytes = size;
	new->next = NULL;
	new->free = FALSE;
	g_global.sum_allocated += size;
	if (!b_start->zone)
		b_start->zone = new;
	else
	{
		new->next = b_start->zone;
		b_start->zone = new;
	}
	return (new);
}