/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:33:36 by asybil            #+#    #+#             */
/*   Updated: 2020/11/24 03:47:23 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		push_all_to_a(t_stack *a, t_stack *b)
{
	while (b->stack_size)
	{
		push_to(b, a, b);
	}
}

void		validate_stack(t_stack *b)
{
	int		biggest_pos;

	biggest_pos = find_biggest(b);
	if (biggest_pos == 1)
	{
		swap(b);
	}
	else if (biggest_pos <= (b->stack_size) / 2)
	{
		repeat(reverse_rotate, biggest_pos, b);
	}
	else
	{
		repeat(rotate, b->stack_size - biggest_pos, b);
	}
}

void		sort_many_values(t_sorter *s)
{
	s->ranges = range_pack_from_stack(s->a);
	move_all_stack_b(s);
	validate_stack(s->b);
	push_all_to_a(s->a, s->b);
}

t_sorter	*create_sorter(void)
{
	t_sorter	*s;

	s = ft_memalloc(sizeof(s));
	s->a = stack_malloc();
	s->b = stack_malloc();
	init_stack(s->a, 'a');
	init_stack(s->b, 'b');
	return (s);
}

int			main(int ac, char **av)
{
	t_sorter	*s;

	if (ac <= 2)
		exit_program_with_err(NULL, NULL, CODE_ERROR);
	s = create_sorter();
	fill_stack(s->a, ac - 1, av + 1);
	if (s->a->stack_size == 3)
	{
		sort_three_values(s->a);
	}
	else
		sort_many_values(s);
	return (0);
}
