/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:33:36 by asybil            #+#    #+#             */
/*   Updated: 2020/11/23 02:35:27 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int		is_smallest_in_stack(stack *b, int number)
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

static int		find_smallest_biggest(stack *b, int number)
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

static int		find_biggest(stack *b)
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

static void		request_insert(stack *b, int number)
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
		request_insert(sorter->b, sorter->a->head->value);
		push_to(sorter->a, sorter->a, sorter->b);
		i++;
	}
}
static void		push_all_to_a(stack *a, stack *b)
{
	while (b->stack_size)
	{
		push_to(b, a, b);
	}
}

static void		validate_stack(stack *b)
{
	int		biggest_pos;

	biggest_pos = find_biggest(b);
	if (biggest_pos == 1)
	{
		swap(b);
	}
	else if (biggest_pos <= (b->stack_size) / 2) {
		repeat(reverse_rotate, biggest_pos, b);
	}
	else
	{
		repeat(rotate, b->stack_size - biggest_pos, b);
	}
}


static void		sort_many_values(sorter *sorter)
{
	sorter->ranges = range_pack_from_stack(sorter->a);
	print_stack(sorter->a[0]);
	print_stack(sorter->b[0]);
	move_all_stack_b(sorter);
	validate_stack(sorter->b);
	push_all_to_a(sorter->a, sorter->b);
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
