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
#define	SMALL 	2
#define	LARGE 	3

/*
 *	N est la taille a partir de laquelle on cree un Small bucket au lieu
 *		d'un Tiny
 *	N est la taille a partir de laquelle on cree un Large bucket au lieu
 *		d'un Medium
 *	
*/

#define N 		(1 * getpagesize())
#define M 		(4 * getpagesize())

/*
 *	Remplacer les Booleens
*/

#define	FALSE 	0
#define	TRUE  	1

typedef struct 			s_zone
{
	size_t				n_bytes;
	int					free;
	struct s_zone		*next;				
}						t_zone;

typedef struct 			s_bucket
{
	size_t				allocated;
	size_t				remaining;
	size_t				size;
	t_zone				*zone;
	struct s_bucket		*next;
}						t_bucket;


typedef struct 			s_global
{
	t_zone				*new_ptr;
	int					sum_allocated;
	int					is_set;
	t_bucket			*tiny;
	t_bucket			*small;
	t_bucket			*large;
}						t_global;

extern					t_global g;
void					print_zones(t_bucket *b);
void					clear_buckets(void);
void					ft_free(void *ptr);
void					*ft_malloc(size_t size);
void					*ft_realloc(void *ptr, size_t size);
t_bucket				*add_tiny_bucket(size_t size);
t_bucket				*add_small_bucket(size_t size);
t_bucket				*add_large_bucket(size_t size);
t_bucket				*find_space(t_bucket *b, size_t size);
t_zone					*new_zone(size_t size, t_bucket *b);
void					show_alloc_mem(void);
void					print_address_hex(void *p0);
char					hex_digit(int v);

#endif