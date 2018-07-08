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
	void	*new_ptr;

	if (g.is_set != TRUE)
	{
		g.is_set = TRUE;
		add_tiny_bucket();
	}
	printf("coucou truc\n");
	if (g.tiny != NULL)
		printf("size du truc : %d\n", g.tiny->size);
	else
		printf("tiny -> NULL\n");
	new_ptr = NULL;
	// Rajouter la verification
	new_ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	return (new_ptr);
}
