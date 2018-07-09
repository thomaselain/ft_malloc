/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 18:36:56 by telain            #+#    #+#             */
/*   Updated: 2018/07/05 18:37:28 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

void		*ft_malloc(size_t size)
{
	t_bucket	*b;

	if (size < N && !(b = find_space(g.tiny, size)))
	{
		add_tiny_bucket(size);
	}
	else if (size < M && !(find_space(g.small, size)))
	{
		add_small_bucket(size);
	}
	else if (size >= M)
	{
		add_large_bucket(size);
	}
	// if (b)
	// {
	// 	printf("On a trouvé de la place dans ce bucket : \n");
	// 	print_debug(b);
	// }
	return ((void*)g.new_ptr);
}
