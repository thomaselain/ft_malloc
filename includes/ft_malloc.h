/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 18:30:53 by telain            #+#    #+#             */
/*   Updated: 2018/07/05 18:30:55 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <fcntl.h>

#		 include <stdio.h>

/*
*	Tailles des buckets
*/

#define	TINY 	1
#define	MEDIUM 	2
#define	LARGE 	3

/*
*	Remplacer les Booleens
*/

#define	TRUE  	1
#define	FALSE 	2

typedef struct 			s_zone
{
	size_t				n_bytes;
	int					free;					
}						t_zone;

typedef struct 			s_bucket
{
	size_t				allocated;
	size_t				remaining;
	int					size;
	t_zone				zone;
	struct s_bucket		*next;
}						t_bucket;


typedef struct 			s_global
{
	int					is_set;
	t_bucket			*tiny;
	t_bucket			*medium;
	t_bucket			*large;
}						t_global;

extern					t_global g;

void					ft_free(void *ptr);
void					*ft_malloc(size_t size);
void					*ft_realloc(void *ptr, size_t size);
void					add_tiny_bucket(void);
void					add_medium_bucket(void);
void					add_large_bucket(void);

#endif