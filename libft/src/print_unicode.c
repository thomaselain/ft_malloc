/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 21:07:17 by telain            #+#    #+#             */
/*   Updated: 2017/05/18 21:27:00 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

static void		display_char(char *w, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		write(1, &w[i], 1);
}
static int		fill_char(int i, int size)
{
	if (size == 1)
		return (1);
	else if (size == 2 && i == 0)
		return (5);
	else if (size == 3 && i == 0)
		return (4);
	else if (size == 4 && i == 0)
		return (3);
	return (6);

}

static wchar_t	get_base(int i, int size)
{
	if (size == 1)
		return (0b00000000);
	else if (size == 2 && i == 0)
		return (0b11000000);
	else if (size == 3 && i == 0)
		return (0b11100000);
	else if (size == 4 && i == 0)
		return (0b11110000);
	return (0b10000000);
}

static int		get_weight(int c)
{
	if (c < 0x80)
		return (1);
	else if (c >= 0x80 && c < 0x7ff)
		return (2);
	else if (c >= 0x7ff && c < 0x1fffff)
		return (3);
	return (4);	
}

void			print_unicode(int c)
{
	wchar_t	a;
	int		i;
	int		j;
	int		size;
	wchar_t	*wchar;

	i = -1;
	size = get_weight(c);
	if (size == 1)
	{
		ft_putchar(c);
		return ;
	}
	fill_char(10, 1);
	printf("size = %d\n", size);
	printf("nb of bytes : %zu\n", ft_strlen(ft_itoa_base(c, 2)));
	ft_putstr("caractere a afficher : ");
	ft_putendl(ft_itoa_base(c, 2));
	ft_putendl("\n");
	wchar = malloc(sizeof(int) * (size));
	while (++i < size)
		wchar[i] = get_base(i, size);
	i = size;
	a = 1 << (ft_strlen(ft_itoa_base(c, 2)) - 1);
	while (--i >= 0)
	{
		j = -1;
		while (++j < 8 - fill_char(i, size))
		{
		printf("c : %s\n", ft_itoa_base(c, 2));
		printf("c >> a : %s\n", ft_itoa_base(c >> a, 2));
		printf("a : %s\n", ft_itoa_base(a, 2));
		printf("wchar[%d] : %s\n\n", i, ft_itoa_base(wchar[i], 2));
		wchar[i] |= (c >> a);
			a >>= 1;
		}
		ft_putendl("");
	}
	display_char((char*)wchar, size);
}
