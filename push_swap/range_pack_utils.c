/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_pack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.21-school.ru >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 02:08:27 by asybil            #+#    #+#             */
/*   Updated: 2020/11/22 02:12:54 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static range_pack	*range_pack_malloc(void)
{
	return (ft_memalloc(sizeof(range_pack)));
}

static int			range_values(int numbers)
{
	int	groups;

	groups = 1;
	groups = groups > 10 && groups <= 24 ? 3 : groups;
	groups = groups > 24 && groups <= 99 ? 4 : groups;
	groups = groups > 100 && groups <= 200 ? 5 : groups;
	groups = groups > 200 && groups <= 350 ? 7 : groups;
	groups = groups > 350 && groups < 700 ? 11 : groups;
	groups = groups > 700 && groups < 1000 ? 15 : groups;
	return (groups);
}

static range_pack 	*pack_from_sorted(int *array, int groups, int numbers)
{
	range_pack	*pack;
	int			i;
	int			j;

	i = 0;
	j = 0;
	pack = ft_memalloc(sizeof(range_pack));
	pack->count_ranges = groups;
	pack->ranges = ft_memalloc(sizeof(range) * groups);
	while (groups > 0)
	{
		j = pack->count_ranges - groups;
		pack->ranges[j].size = numbers / pack->count_ranges;
		pack->ranges[j].size += groups == 1 ? numbers % pack->count_ranges : 0;
		pack->ranges[j].array = ft_memalloc(sizeof(int) * pack->ranges[j].size);
		while (i < pack->ranges[j].size)
		{
			pack->ranges[j].array[i] = array[j * pack->count_ranges + i];
			i++;
		}
		j++;
		i = 0;
		groups--;
	}
	return (pack);
}

static int			*get_int_from_stack(stack *stack)
{
	int		*ints;
	t_item	*tmp;
	int		i;

	ints = ft_memalloc(sizeof(int) * stack->stack_size);
	tmp = stack->head;
	i = 0;
	while (tmp)
	{
		ints[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (ints);
}

range_pack			*range_pack_from_stack(stack *stack)
{
	int		*ints;

	ints = get_int_from_stack(stack);
	quick_sort(ints, 0, (stack->stack_size));
	return (pack_from_sorted(ints, range_values(stack->stack_size), stack->stack_size));
}
