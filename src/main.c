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
	void 	*void1, *void2;

	if (ac || av)
		;
	str1 = (char*)ft_malloc(sizeof(char) * 8090);
	str2 = (char*)ft_malloc(sizeof(char) * 100);
	// int1 = (int*)ft_malloc(sizeof(int) * 10);
	// int2 = (int*)ft_malloc(sizeof(int) * 10);
	// void1 = (void*)ft_malloc(sizeof(void) * 10);
	// void2 = (void*)ft_malloc(sizeof(void) * 10);

	printf("Affichage de tous les buckets :\n");
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