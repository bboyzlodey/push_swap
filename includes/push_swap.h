/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:34:25 by asybil            #+#    #+#             */
/*   Updated: 2020/11/25 00:26:27 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"

# ifndef PS_VERBOSE
#  define PS_VERBOSE 0
# endif

typedef enum	e_exit_code {
	CODE_OK,
	CODE_KO,
	CODE_ERROR,
	CODE_SUCCESS,
	CODE_MEMMORY_ERROR
}				t_exit_code;

typedef struct	s_item
{
	int				value;
	struct s_item	*next;
	struct s_item	*prev;
}				t_item;

typedef struct	s_stack {
	t_item	*head;
	t_item	*foots;
	int		stack_size;
	char	identifier;
}				t_stack;

typedef struct	s_range
{
	int	*array;
	int	size;
}				t_range;

typedef struct	s_range_pack
{
	t_range	*ranges;
	int		count_ranges;
}				t_range_pack;

typedef struct	s_sorter
{
	t_stack			*a;
	t_stack			*b;
	t_range_pack	*ranges;
}				t_sorter;

typedef void	(*t_action)(t_stack*);

void			refresh_foots(t_stack*a);

t_action		get_action(char *av);
t_stack			*get_choosed_stack(t_stack*a, t_stack *b, char *av);

void			push(t_stack*push, t_item *item);
t_item			*pop(t_stack*pop);
void			swap(t_stack*swap);
void			rotate(t_stack*rotate);
void			reverse_rotate(t_stack*rev_rotate);
void			repeat(t_action func, int times, t_stack *arg);
int				contain(int number, t_stack *s);

/*
**	stack_utils.c
*/

void			init_stack(t_stack*to_init, char identifier);
void			fill_stack(t_stack*to_fill, int ac, char **av, t_stack *b);
int				is_sorted_stack(t_stack*sorted);
t_stack			*stack_malloc(void);
void			free_stack(t_stack *clear);

void			exit_program_with_err(t_stack*a, t_stack *b, t_exit_code code);
void			move_all_stack_b(t_sorter *s);
void			request_insert(t_stack*b, int number);
int				find_biggest(t_stack*b);
int				find_smallest_biggest(t_stack*b, int number);
int				is_smallest_in_stack(t_stack*b, int number);
t_sorter		*create_sorter(void);
void			sort_many_values(t_sorter *s);
void			validate_stack(t_stack*b);
void			push_all_to_a(t_stack*a, t_stack*b);
/*
**	instructions_utils.c
*/

void			swap_ints(int *first, int *second);
/*
** instructions.c
*/
void			push_to(t_stack*from, t_stack*a, t_stack*b);

/*
**	item_utils.c
*/

int				init_item(t_item *item, char *value);
t_item			*item_malloc(void);
t_item			*item_from_int(int val);

/*
**	debug_utils.c
*/
void			print_stack(t_stack print);
void			range_pack_verbose(t_sorter *s);

/*
**	sorter.c
*/
t_sorter		*new_sorter(t_stack*a, t_stack*b);

/*
**	quick_sort.c
*/
void			quick_sort(int *array, int start, int end);

/*
** 	range_utils.c
*/
t_range			*ft_find_min_max(t_stack*a, t_stack*b);
int				find_near_int(t_range *r, t_stack*a);

/*
** range_pack_utils.c
*/

t_range_pack	*range_pack_from_stack(t_stack*s);

/*
**	sort algorithms
*/

int				sort_three_values(t_stack*a);
int				sort_five_values(t_stack*a, t_stack*b);

#endif
