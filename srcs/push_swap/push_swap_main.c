/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:33:36 by asybil            #+#    #+#             */
/*   Updated: 2020/11/25 01:01:01 by asybil           ###   ########.fr       */
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

t_sorter	*create_sorter(void)
{
	t_sorter	*s;

	s = ft_memalloc(sizeof(t_sorter));
	s->a = stack_malloc();
	s->b = stack_malloc();
	init_stack(s->a, 'a');
	init_stack(s->b, 'b');
	return (s);
}

static void	sucess_end(t_sorter *s)
{
	int				i;
	t_range			*tmp;
	t_range_pack	*pack;

	tmp = NULL;
	pack = s->ranges;
	i = 0;
	free_stack(s->a);
	free_stack(s->b);
	while (s->ranges && i < (s->ranges->count_ranges))
	{
		tmp = ((s->ranges->ranges) + i);
		ft_memdel((void*)&(tmp->array));
		i++;
	}
	if (pack)
	{
		tmp = pack->ranges;
		ft_memdel((void*)&tmp);
	}
	ft_memdel((void*)&pack);
	ft_memdel((void*)&s);
}

int			main(int ac, char **av)
{
	t_sorter	*s;

	if (ac < 2)
		exit_program_with_err(NULL, NULL, CODE_ERROR);
	s = create_sorter();
	fill_stack(s->a, ac - 1, av + 1, s->b);
	if (s->a->stack_size == 3)
	{
		sort_three_values(s->a);
	}
	else if (s->a->stack_size <= 2)
	{
		if (s->a->head->value > s->a->foots->value)
		{
			swap(s->a);
		}
	}
	else
		sort_many_values(s);
	sucess_end(s);
	return (0);
}
