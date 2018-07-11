/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 15:07:34 by telain            #+#    #+#             */
/*   Updated: 2018/07/11 21:11:46 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

char		hex_digit(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('A' + v - 10);
}

void		print_address_hex(void *p0)
{
	int			i;
	uintptr_t	p;

	ft_putchar('0');
	ft_putchar('x');
	p = (uintptr_t)p0;
	i = (sizeof(p) << 3) - 4;
	while (i >= 0)
	{
		ft_putchar(hex_digit((p >> i) & 0xf));
		i -= 4;
	}
}

void		print_each_zone(t_bucket *b)
{
	t_bucket	*tmp;

	tmp = b;
	while (tmp)
	{
		print_zones(tmp);
		tmp = tmp->next;
	}
}

void		show_alloc_mem(void)
{
	if (g_global.is_set != TRUE)
		return ;
	ft_putendl("TINY Allocations");
	print_each_zone(g_global.tiny);
	ft_putendl("\nSMALL Allocations");
	print_each_zone(g_global.small);
	ft_putendl("\nLARGE Allocations");
	print_each_zone(g_global.large);
	ft_putstr("Total : ");
	ft_putnendl(g_global.sum_allocated);
	ft_putstr("bytes\n");
}
