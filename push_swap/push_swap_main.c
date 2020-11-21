/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.21-school.ru >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:33:36 by asybil            #+#    #+#             */
/*   Updated: 2020/11/22 02:24:31 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


static void		sort_many_values(sorter *sorter)
{
	sorter->ranges = range_pack_from_stack(sorter->a);
	printf("size of ranges: %d\n", (sorter->ranges->count_ranges));
	int i = 0;
	while (i < (sorter->ranges->count_ranges))
	{
		int j = 0;
		while (j < sorter->ranges->ranges[i].size)
		{
			printf("range: %5d | item: %5d | value: %d\n", j, i, sorter->ranges->ranges[i].array[j]);
			j++;
		}
		i++;
	}
}

static sorter	*create_sorter(void)
{
	sorter	*sorter;

	sorter = ft_memalloc(sizeof(sorter));
	sorter->a = stack_malloc();
	sorter->b = stack_malloc();
	init_stack(sorter->a, 'a');
	init_stack(sorter->b, 'b');
	return (sorter);
}
int	main(int ac, char **av)
{
	sorter	*sorter;
	
	if (ac <= 2)
		exit_program_with_err(NULL, NULL, CODE_ERROR);
	sorter = create_sorter();
	fill_stack(sorter->a, ac - 1, av + 1);
	if (sorter->a->stack_size == 3)
	{
		sort_three_values(sorter->a);
	}
	else if (sorter->a->stack_size > 3 && sorter->a->stack_size <= 5)
	{
		
	}
	else
		sort_many_values(sorter);
	print_stack(*(sorter->a));
	printf("Operations: %d\n", count_of_operations);
	return (0);
}
