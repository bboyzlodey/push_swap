/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:51:55 by asybil            #+#    #+#             */
/*   Updated: 2020/11/24 03:43:34 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
**	Map of compares:
** 	raw_map[0] - compare top_to_middle
** 	raw_map[1] - compare middle_to_bottom
** 	raw_map[2] - compare bottom_to_top
**	Where value of 1 is '>', -1 is '<'.
*/

static void	get_compared_map(int *raw_map, t_stack *a)
{
	raw_map[0] = a->head->value > a->head->next->value ? 1 : -1;
	raw_map[1] = a->head->next->value > a->foots->value ? 1 : -1;
	raw_map[2] = a->foots->value > a->head->value ? 1 : -1;
}

/*
**	Return value: -1 if can`t sorted. 0 - sorted.
*/

int			sort_three_values(t_stack *a)
{
	int	compared_map[3];

	if (a->stack_size != 3)
		return (-1);
	if (!is_sorted_stack(a))
		return (0);
	get_compared_map(compared_map, a);
	if (compared_map[2] == -1)
	{
		if (compared_map[0] > compared_map[1])
			reverse_rotate(a);
		else if (compared_map[0] < compared_map[1])
			rotate(a);
		else
			swap(a);
	}
	else
		swap(a);
	return (sort_three_values(a));
}

/*
** 	TODO
*/

int			sort_five_values(t_stack *a, t_stack *b)
{
	while (a->stack_size != 3)
		push_to(a, a, b);
	sort_three_values(a);
	if (b->stack_size == 2)
	{
		if (b->head->value < b->head->next->value)
		{
			return (1);
		}
	}
	return (1);
}
