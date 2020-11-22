/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.21-school.ru >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:33:36 by asybil            #+#    #+#             */
/*   Updated: 2020/11/22 19:27:01 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void		move_all_stack_b(sorter *sorter)
{
	int	i;
	int	count_ranges;

	count_ranges = sorter->ranges->ranges[0].size;
	i = 0;
	range_pack_verbose(sorter);
	while (sorter->a->stack_size)
	{
		if (i / count_ranges >= sorter->ranges->count_ranges)
		{
			find_near_int((sorter->ranges->ranges) + ((sorter->ranges->count_ranges) - 1), sorter->a);
		}
		else	
			find_near_int((sorter->ranges->ranges) + (i / count_ranges), sorter->a);
		push_to(sorter->a, sorter->a, sorter->b);
		i++;
	}
}
static void		sort_many_values(sorter *sorter)
{
	sorter->ranges = range_pack_from_stack(sorter->a);
	print_stack(sorter->a[0]);
	print_stack(sorter->b[0]);
	move_all_stack_b(sorter);
	print_stack(sorter->a[0]);
	print_stack(sorter->b[0]);
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
