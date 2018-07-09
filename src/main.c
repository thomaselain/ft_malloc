/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 18:05:17 by telain            #+#    #+#             */
/*   Updated: 2018/07/05 18:05:19 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

t_global	g;

int main(int ac, char **av)
{
	char	*str1, *str2;
	int 	*int1, *int2;
	void 	*void1, *void2, *void3;

	if (ac || av)
		;
	printf("\e[31mN = %d\nM = %d\n\n\e[0m", N, M);
	// Tiny mallocs
	ft_malloc(4384);
	ft_malloc(500);
	ft_malloc(500);
	ft_malloc(123);
	ft_malloc(12);
	ft_malloc(1);
	// Small mallocs
	ft_malloc(10000);
	ft_malloc(13434);
	// Large mallocs
	ft_malloc(100000000);
	ft_malloc(100000000);
	ft_malloc(100000000);
	// Malloc Vide
	ft_malloc(0);



	// int1 = (int*)ft_malloc(sizeof(int)*6000);
	// int2 = (int*)ft_malloc(sizeof(int)*12);
	// void1 = (void*)ft_malloc(sizeof(void)*2);
	// void2 = (void*)ft_malloc(sizeof(void)*1);
	// void3 = (void*)ft_malloc(sizeof(void)*342);

	t_bucket	*tmp;
	tmp = g.tiny;
	printf("Tiny buckets\n---------------------------------\n");
	while (tmp)
	{
		print_debug(tmp);
		tmp = tmp->next;
	}
	printf("---------------------------------\n\n");
	tmp = g.small;
	printf("Small buckets\n---------------------------------\n");
	while (tmp)
	{
		print_debug(tmp);
		tmp = tmp->next;
	}
	printf("---------------------------------\n\n");
	tmp = g.large;
	printf("Large buckets\n---------------------------------\n");
	while (tmp)
	{
		print_debug(tmp);
		tmp = tmp->next;
	}
	printf("---------------------------------\n\n");
	// str1 = "salut1";
	// printf("%s\n", str1);
	// str2 = "salut2";
	// printf("%s\n", str2);
	return (0);
}