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

int main(int ac, char **av)
{
	char	*str1;
	char	*str2;

	if (ac || av)
		;
	str1 = (char*)ft_malloc(sizeof(char) * 10);
	str2 = (char*)ft_malloc(sizeof(char) * 10);
	printf("%s\n", str1);
	str2 = "salut2";
	printf("%s\n", str2);
	return (0);
}