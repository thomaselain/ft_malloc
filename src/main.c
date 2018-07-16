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
	printf("\e[31mN = %d\nM = %d\e[0m\n\n", N, M);

	ft_malloc(10000000);
	ft_malloc(10000000);
	ft_malloc(10000000);
	ft_malloc(10000000);
	ft_malloc(1000000);
	ft_malloc(100000);
	ft_malloc(100000);
	ft_malloc(100000);
	ft_malloc(100000);
	ft_malloc(10000);
	ft_malloc(1000);
	ft_malloc(100);
	ft_malloc(10);
	ft_malloc(10);
	ft_malloc(10);
	ft_malloc(1);
	ft_malloc(1);
	ft_malloc(1);
	ft_malloc(0);

	show_alloc_mem();

	// int1 = (int*)ft_malloc(sizeof(int)*6000);
	// int2 = (int*)ft_malloc(sizeof(int)*12);
	// void1 = (void*)ft_malloc(sizeof(void)*2);
	// void2 = (void*)ft_malloc(sizeof(void)*1);
	// void3 = (void*)ft_malloc(sizeof(void)*342);

	// str1 = "salut1";
	// printf("%s\n", str1);
	// str2 = "salut2";
	// printf("%s\n", str2);
	return (0);
}



