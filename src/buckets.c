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

t_global		g_global;

void			clear_buckets(void)	// TO DO (ca devrait juste ressembler a ca)
{
	munmap(g_global.tiny, sizeof(t_bucket*));
	munmap(g_global.small, sizeof(t_bucket*));
	munmap(g_global.large, sizeof(t_bucket*));
}

t_bucket		*add_tiny_bucket(size_t size)
{
	t_bucket	*tmp;
	t_bucket	*new;

	if (g_global.tiny == NULL)
	{
		g_global.tiny = (t_bucket*)mmap(NULL, sizeof(t_bucket),
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		g_global.tiny->size = N;
		g_global.tiny->remaining = N;
		g_global.tiny->allocated = 0;
		return (g_global.tiny);
	}
	new = (t_bucket*)mmap(NULL, sizeof(t_bucket),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	new->size = N;
	new->remaining = N;
	new->allocated = 0;
	tmp = g_global.tiny;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}

t_bucket		*add_small_bucket(size_t size)
{
	t_bucket	*tmp;
	t_bucket	*new;

	if (g_global.small == NULL)
	{
		g_global.small = (t_bucket*)mmap(NULL, sizeof(t_bucket),
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		g_global.small->size = M;
		g_global.small->remaining = M;
		g_global.small->allocated = 0;
		return (g_global.small);
	}
	new = (t_bucket*)mmap(NULL, sizeof(t_bucket),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	new->size = M;
	new->remaining = M;
	new->allocated = 0;
	tmp = g_global.small;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}

t_bucket		*add_large_bucket(size_t size)
{
	t_bucket	*tmp;
	t_bucket	*new;

	if (g_global.large == NULL)
	{
		g_global.large = (t_bucket*)mmap(NULL, sizeof(t_bucket),
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		g_global.large->size = size;
		g_global.large->allocated = 0;
		g_global.large->remaining = size;
		return (g_global.large);
	}
	new = (t_bucket*)mmap(NULL, sizeof(t_bucket),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	new->size = size;
	new->allocated = 0;
	new->remaining = size;
	tmp = g_global.large;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}

t_bucket		*find_space(t_bucket *b, size_t size)
{
	t_bucket	*tmp;

	tmp = b;
	while (tmp)
	{
		if (tmp->remaining >= size)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}
