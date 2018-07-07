/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buckets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 15:46:11 by telain            #+#    #+#             */
/*   Updated: 2018/07/06 15:59:26 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

void			add_tiny_bucket(void)
{
	t_bucket 	*tmp;
	t_bucket	new;

	new.size = TINY;
	tmp = g.large;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = &new;
}

void			add_medium_bucket(void)
{
	t_bucket 	*tmp;
	t_bucket	new;

	new.size = MEDIUM;
	tmp = g.large;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = &new;
}

void			add_large_bucket(void)
{
	t_bucket 	*tmp;
	t_bucket	new;

	new.size = LARGE;
	tmp = g.large;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = &new;
}