/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 18:31:49 by telain            #+#    #+#             */
/*   Updated: 2018/07/05 18:31:49 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct 		s_flag
{
	struct flag		*prev;
	char			*p;
	struct flag		*next;
}					t_flag;