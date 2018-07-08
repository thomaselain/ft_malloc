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
	t_bucket	*new;

	if (!g.tiny)
	{
		printf("%d\n", g.is_set);
		g.tiny = (t_bucket*)mmap(NULL, sizeof(t_bucket), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		if (g.tiny != NULL)
			printf("premier\n");
		return ;
	}
	new = (t_bucket*)mmap(NULL, sizeof(t_bucket), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	new->size = TINY;
	tmp = g.tiny;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}










void			add_medium_bucket(void)
{
	t_bucket 	*tmp;
	t_bucket	new;

	new.size = MEDIUM;
	tmp = g.medium;
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