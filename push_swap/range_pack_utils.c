/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_pack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 02:08:27 by asybil            #+#    #+#             */
/*   Updated: 2020/11/23 01:42:49 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int			range_values(int numbers)
{
	int	groups;

	groups = 1;
	groups = numbers > 10 && numbers <= 24 ? 3 : groups;
	groups = numbers > 24 && numbers <= 99 ? 4 : groups;
	groups = numbers > 100 && numbers <= 200 ? 5 : groups;
	groups = numbers > 200 && numbers <= 350 ? 7 : groups;
	groups = numbers > 350 && numbers < 700 ? 11 : groups;
	groups = numbers > 700 && numbers < 1000 ? 15 : groups;
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

static int			print_int_arr(int *array, int size)
{
	int i = 0;
	printf("Print int array[%d]\n", size);
	while (i < size)
	{
		printf("%3d: [%4d]\n", i , array[i]);
		i++;
	}
	return (0);
}
range_pack			*range_pack_from_stack(stack *stack)
{
	int		*ints;

	ints = get_int_from_stack(stack);
	quick_sort(ints, 0, (stack->stack_size) - 1);
	print_int_arr(ints, stack->stack_size);
	return (pack_from_sorted(ints, range_values(stack->stack_size), (stack->stack_size) - 1));
}
