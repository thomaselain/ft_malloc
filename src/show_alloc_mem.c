/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 15:07:34 by telain            #+#    #+#             */
/*   Updated: 2018/07/11 15:07:46 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

char		hex_digit(int v) {
    if (v >= 0 && v < 10)
        return '0' + v;
    else
        return 'a' + v - 10;
}

void		print_address_hex(void* p0) {
    int			i;
    uintptr_t	p;

    ft_putchar('0');
    ft_putchar('x');
    p = (uintptr_t)p0;
    for(i = (sizeof(p) << 3) - 4; i>=0; i -= 4) {
        ft_putchar(hex_digit((p >> i) & 0xf));
    }
}

void		show_alloc_mem(void)
{
	t_bucket	*tmp;

	if (g.is_set != TRUE)
	 	return ;
	tmp = g.tiny;
	ft_putendl("TINY Allocations");
	while (tmp)
	{
		print_zones(tmp);
		tmp = tmp->next;
	}
	ft_putendl("\nSMALL Allocations");
	tmp = g.small;
	while (tmp)
	{
		print_zones(tmp);
		tmp = tmp->next;
	}
	ft_putendl("\nLARGE Allocations");
	tmp = g.large;
	while (tmp)
	{
		print_zones(tmp);
		tmp = tmp->next;
	}
	ft_putstr("Total : ");
	ft_putnendl(g.sum_allocated);
	ft_putstr("bytes\n");
}