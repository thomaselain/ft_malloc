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

t_bucket		*add_bucket(t_bucket **b, size_t size, size_t bucket_size)
{
	t_bucket	*new;

	printf("\e[34mNew bucket (%s)\e[0m\n", (bucket_size == N ? "Tiny" : (bucket_size == M ? "Small" : "Large")));

	new = (t_bucket*)mmap(NULL, sizeof(t_bucket),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	new->size = bucket_size;
	new->remaining = bucket_size;
	new->allocated = 0;
	new->next = *b;
	*b = new;
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
