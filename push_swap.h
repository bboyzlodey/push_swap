/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.21-school.ru >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:34:25 by asybil            #+#    #+#             */
/*   Updated: 2020/10/28 02:09:45 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"


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
	int	from;
	int	to;
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
	range		*min_max;
};

typedef	struct s_sorter sorter;

typedef void (*action)(stack*);

// void	push(stack from, stack to);
void	push(stack *push, t_item *item);
t_item	*pop(stack *pop);
void	swap(stack *swap);
void	rotate(stack *rotate);
void	reverse_rotate(stack *rev_rotate);

/*
*	stack_utils.c
*/
void	init_stack(stack *to_init, char identifier);
void	fill_stack(stack *to_fill, int ac, char **av);
int		is_sorted_stack(stack *sorted);
stack	*stack_malloc(void);

void	exit_program_with_err(stack *a, stack *b, exit_code code);

/*
*	instructions_utils.c
*/
void	swap_ints(int *first, int *second);

/*
*	item_utils.c
*/

int		init_item(t_item *item, char *value);
t_item	*item_malloc(void);
t_item	*item_from_int(int val);

/*
*	debug_utils.c
*/
void	print_stack(stack print);

/*
*	sorter.c
*/
sorter	*new_sorter(stack *a, stack *b);

/*
** 	range_utils.c
*/
range	*ft_find_min_max(stack *a, stack *b);

#endif