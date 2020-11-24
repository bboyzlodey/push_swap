/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 02:43:39 by asybil            #+#    #+#             */
/*   Updated: 2020/11/24 03:00:47 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		is_smallest_in_stack(stack *b, int number)
{
	t_item	*tmp;

	tmp = b->head;
	while (tmp)
	{
		if ((tmp->value) < number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		find_smallest_biggest(stack *b, int number)
{
	int		found;
	t_item	*tmp;
	int		i;
	int		position;

	i = 0;
	tmp = b->head;
	position = 0;
	found = 0;
	while (tmp)
	{
		if (found < (tmp->value) && (tmp->value) < number)
		{
			position = i;
			found = (tmp->value);
		}
		i++;
		tmp = tmp->next;
	}
	return (position);
}

int		find_biggest(stack *b)
{
	t_item	*tmp;
	int		biggest;
	int		position;
	int		i;

	tmp = b->head;
	biggest = 0;
	position = 0;
	i = 0;
	while (tmp)
	{
		if (biggest < (tmp->value))
		{
			biggest = (tmp->value);
			position = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (position);
}

void	request_insert(stack *b, int number)
{
	int		target_pos;

	target_pos = 0;
	if (is_smallest_in_stack(b, number))
	{
		target_pos = find_biggest(b);
	}
	else
	{
		target_pos = find_smallest_biggest(b, number);
	}
	if (target_pos <= (b->stack_size) / 2)
	{
		repeat(reverse_rotate, target_pos, b);
	}
	else
	{
		repeat(rotate, b->stack_size - target_pos, b);
	}
}

void	move_all_stack_b(sorter *s)
{
	int	i;
	int	count_ranges;

	count_ranges = s->ranges->ranges[0].size;
	i = 0;
	while (s->a->stack_size)
	{
		if (i / count_ranges >= s->ranges->count_ranges)
		{
			find_near_int((s->ranges->ranges) + \
			((s->ranges->count_ranges) - 1), s->a);
		}
		else
			find_near_int((s->ranges->ranges) + (i / count_ranges), s->a);
		request_insert(s->b, s->a->head->value);
		push_to(s->a, s->a, s->b);
		i++;
	}
}
