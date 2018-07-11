/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 20:48:56 by telain            #+#    #+#             */
/*   Updated: 2018/07/09 20:48:58 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

void		*ft_malloc(size_t size)
{
	t_bucket	*b;

	g_global.is_set = TRUE;
	if (size == 0)
		return (NULL);
	if (size < N && !(b = find_space(g_global.tiny, size)))
	{
		b = add_tiny_bucket(size);
	}
	else if (size < M && !(b = find_space(g_global.small, size)))
	{
		b = add_small_bucket(size);
	}
	else if (size >= M)
	{
		b = add_large_bucket(size);
	}
	g_global.new_ptr = new_zone(size, b);
	return ((void*)g_global.new_ptr);
}
