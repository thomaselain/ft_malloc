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

t_global		g;

void		clear_buckets(void)			// TO DO (ca devrait juste ressembler a ca)
{
	munmap(g.tiny, sizeof(t_bucket*));
	munmap(g.small, sizeof(t_bucket*));
	munmap(g.large, sizeof(t_bucket*));
}

t_bucket		*add_tiny_bucket(size_t size)
{
	t_bucket 	*tmp;
	t_bucket	*new;

	if (g.tiny == NULL)
	{
		g.tiny = (t_bucket*)mmap(NULL, sizeof(t_bucket), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		g.tiny->size = N;
		g.tiny->remaining = N;
		g.tiny->allocated = 0;
		return g.tiny;
	}
	new = (t_bucket*)mmap(NULL, sizeof(t_bucket), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	new->size = N;
	new->remaining = N;
	new->allocated = 0;
	tmp = g.tiny;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}

t_bucket		*add_small_bucket(size_t size)
{
	t_bucket 	*tmp;
	t_bucket	*new;

	if (g.small == NULL)
	{
		g.small = (t_bucket*)mmap(NULL, sizeof(t_bucket), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		g.small->size = M;
		g.small->remaining = M;
		g.small->allocated = 0;
		return g.small;
	}
	new = (t_bucket*)mmap(NULL, sizeof(t_bucket), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	new->size = M;
	new->remaining = M;
	new->allocated = 0;
	tmp = g.small;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}

t_bucket		*add_large_bucket(size_t size)
{
	t_bucket 	*tmp;
	t_bucket	*new;

	if (g.large == NULL)
	{
		g.large = (t_bucket*)mmap(NULL, sizeof(t_bucket), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		g.large->size = size;
		g.large->allocated = 0;
		g.large->remaining = size;
		return g.large;
	}
	new = (t_bucket*)mmap(NULL, sizeof(t_bucket), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	new->size = size;
	new->allocated = 0;
	new->remaining = size;
	tmp = g.large;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}

t_bucket		*find_space(t_bucket *b, size_t size)
{
	t_bucket 		*tmp;

	tmp = b;
	while (tmp)
	{
		if (tmp->remaining >= size)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}