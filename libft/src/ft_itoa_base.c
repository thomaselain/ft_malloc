/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 10:01:42 by exam              #+#    #+#             */
/*   Updated: 2016/04/19 10:26:24 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	int		length;
	int		sign;
	int		bck;
	char	*ret;

	bck = value;
	length = 1;
	sign = value < 0 ? 1 : 0;
	if (base != 10)
		sign = 0;
	if (base < 2 || base > 16)
		return (NULL);
	while (bck /= base)
		length++;
	if (!(ret = (char *)malloc(sizeof(char) * length + sign + 1)))
		return (NULL);
	ret[length + sign] = '\0';
	ret[0] = '-';
	while (length--)
	{
		ret[length + sign] = value < 0 ? (-(value % -(base))) + 48: (value % base) + 48;
		if (ret[length + sign] > 57)
			ret[length + sign] += 7;
		value /= base;
	}
	return (ret);
}
