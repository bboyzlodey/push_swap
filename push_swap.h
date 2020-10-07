#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>

typedef struct	s_stack {
	int		*values;
	int		stack_size;
	int		stack_values;
	char	identifier;
}				t_stack;

typedef t_stack stack;

void	push(stack from, stack to);
void	swap(stack swap);
void	rerange(stack rerange);
void	reverse_rerange(stack rev_rerange);

void	init_stack(stack to_init, int size, char identifier);
void	fill_stack(stack to_fill, int ac, char **av);

#endif