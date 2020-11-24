/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_pack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 02:08:27 by asybil            #+#    #+#             */
/*   Updated: 2020/11/24 02:40:51 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/libft.h"

static int			range_values(int numbers)
{
	int	groups;

	groups = 2;
	groups = numbers > 10 && numbers <= 24 ? 3 : groups;
	groups = numbers > 24 && numbers <= 99 ? 4 : groups;
	groups = numbers > 100 && numbers <= 200 ? 5 : groups;
	groups = numbers > 200 && numbers <= 350 ? 7 : groups;
	groups = numbers > 350 && numbers < 700 ? 11 : groups;
	groups = numbers > 700 && numbers < 1000 ? 15 : groups;
	return (groups);
}

static range_pack	*pack_from_sorted(int *array, int groups, int numbers)
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

static int			*get_int_from_stack(stack *a)
{
	int		*ints;
	t_item	*tmp;
	int		i;

	ints = ft_memalloc(sizeof(int) * a->stack_size);
	tmp = a->head;
	i = 0;
	while (tmp)
	{
		ints[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (ints);
}

range_pack			*range_pack_from_stack(stack *a)
{
	int			*ints;
	range_pack	*tmp;

	tmp = NULL;
	ints = get_int_from_stack(a);
	quick_sort(ints, 0, (a->stack_size) - 1);
	tmp = pack_from_sorted(ints, range_values(a->stack_size),\
							(a->stack_size) - 1);
	ft_memdel((void*)&ints);
	return (tmp);
}
