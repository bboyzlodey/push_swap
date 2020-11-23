/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:34:25 by asybil            #+#    #+#             */
/*   Updated: 2020/11/23 04:53:29 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"

# ifndef PS_VERBOSE
# define PS_VERBOSE 0
# endif

int count_of_operations;

typedef enum	e_exit_code {
	CODE_OK,
	CODE_KO,
	CODE_ERROR,
	CODE_SUCCESS,
	CODE_MEMMORY_ERROR
}				t_exit_code;

typedef	t_exit_code exit_code;

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

typedef t_stack stack;

struct s_range
{
	int	*array;
	int	size;
};

typedef struct s_range range;

struct s_range_pack
{
	range	*ranges;
	int		count_ranges;
};

typedef struct s_range_pack range_pack;

struct s_sorter
{
	stack		*a;
	stack		*b;
	range_pack	*ranges;
};

typedef	struct s_sorter sorter;

typedef void (*action)(stack*);

typedef void (*repeat_action)(action,int, stack *);

action		get_action(char *av);
stack		*get_choosed_stack(stack *a, stack *b, char *av);


void		push(stack *push, t_item *item);
t_item		*pop(stack *pop);
void		swap(stack *swap);
void		rotate(stack *rotate);
void		reverse_rotate(stack *rev_rotate);
void		repeat(action func, int times, stack *arg);
/*
**	stack_utils.c
*/
void		init_stack(stack *to_init, char identifier);
void		fill_stack(stack *to_fill, int ac, char **av);
int			is_sorted_stack(stack *sorted);
stack		*stack_malloc(void);

void		exit_program_with_err(stack *a, stack *b, exit_code code);

/*
**	instructions_utils.c
*/

void		swap_ints(int *first, int *second);
/*
** instructions.c
*/
void		push_to(stack *from, stack *a, stack *b);

/*
**	item_utils.c
*/

int			init_item(t_item *item, char *value);
t_item		*item_malloc(void);
t_item		*item_from_int(int val);

/*
**	debug_utils.c
*/
void		print_stack(stack print);
void		range_pack_verbose(sorter *sorter);

/*
**	sorter.c
*/
sorter		*new_sorter(stack *a, stack *b);

/*
**	quick_sort.c
*/
void		quick_sort(int *array, int start, int end);

/*
** 	range_utils.c
*/
range		*ft_find_min_max(stack *a, stack *b);
int			find_near_int(range *range, stack *a);
void		refresh_foots(stack *stack);

/*
** range_pack_utils.c
*/

range_pack	*range_pack_from_stack(stack *stack);

/*
**	sort algorithms 
*/

int			sort_three_values(stack *a);
int			sort_five_values(stack *a, stack *b);

#endif