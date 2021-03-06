/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:36:00 by asybil            #+#    #+#             */
/*   Updated: 2020/11/24 03:43:21 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	int_in_range(int check, t_range *r)
{
	int	i;

	i = 0;
	while (i < r->size)
	{
		if (r->array[i] == check)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static void	find_top_bottom(int *top, int *bottom, t_range *r, t_stack *a)
{
	t_item	*tmp;
	int		top_founded;

	top_founded = 0;
	tmp = a->head;
	while (tmp)
	{
		if (int_in_range(tmp->value, r))
		{
			*bottom = tmp->value;
			if (!top_founded)
			{
				top_founded = 1;
				*top = *bottom;
			}
		}
		tmp = tmp->next;
	}
}

static void	move_to_top(int top, int bottom, t_stack *a)
{
	t_item	*tmp;
	int		top_pos;
	int		bottom_pos;
	int		i;

	i = 0;
	top_pos = 0;
	bottom_pos = 0;
	tmp = a->head;
	while (tmp)
	{
		if (top == (tmp->value))
			top_pos = i;
		else if ((tmp->value) == bottom)
			bottom_pos = i;
		i++;
		tmp = tmp->next;
	}
	if (top_pos < a->stack_size - bottom_pos)
		repeat(reverse_rotate, top_pos, a);
	else
		repeat(reverse_rotate, a->stack_size - bottom_pos, a);
}

int			find_near_int(t_range *r, t_stack *a)
{
	int	top;
	int	bottom;

	top = 0;
	bottom = 0;
	find_top_bottom(&top, &bottom, r, a);
	move_to_top(top, bottom, a);
	return (0);
}
