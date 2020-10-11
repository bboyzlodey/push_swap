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
	int		value;
	t_item	*next;
	t_item	*prev;
}				t_item;


typedef struct	s_stack {
	t_item	*head;
	t_item	*foots;
	int		stack_size;
	char	identifier;
}				t_stack;

typedef t_stack stack;

void	push(stack from, stack to);
void	swap(stack swap);
void	rotate(stack rotate);
void	reverse_rotate(stack rev_rotate);

void	init_stack(stack *to_init, char identifier);
void	fill_stack(stack *to_fill, int ac, char **av);

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

#endif