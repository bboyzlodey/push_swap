/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:33:36 by asybil            #+#    #+#             */
/*   Updated: 2020/11/26 23:46:43 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
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

static t_item	*find_first_position_int(range *current, stack *a)
{
	t_item	*tmp;

	tmp = a->head;
	tmp = NULL;
	while (tmp)
	{
		if (int_in_range(tmp->value, current))
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

static t_item	*find_last_position_int(range *current, stack *a)
{
	t_item	*tmp;
	t_item	*last_pos;

	last_pos = 0;
	tmp = a->head;
	while (tmp)
	{
		if (int_in_range(tmp->value, current))
			last_pos = tmp->pos;
		tmp = tmp->next;
	}
	return (last_pos);
}

static	action	action_item(int pos, int stack_size)
{
	return (stack_size - pos - 1 < pos + 1) ? rotate : reverse_rotate;
}

static t_item	*find_best_position(int number, stack *a)
{
	t_item	*biggest;
	t_item	*big_small;
	t_item	*tmp;

	big_small = NULL;
	biggest = a->head;
	tmp = a->head;
	while (tmp)
	{
		if (biggest->value < tmp->value)
			biggest = tmp;
		if (big_small == 0 || tmp->value > big_small->value && tmp->value < number)
			big_small = tmp;
		tmp = tmp->next;
	}
	if (big_small != 0)
		tmp = big_small;
	else
		tmp = biggest;
	tmp->callback = action_item(tmp->pos, a->stack_size);
	tmp->count = lost_steps_to_up(a->stack_size, tmp->pos);
	return (biggest);
}

static	t_item	*choose_best_number(t_item *one, t_item *two, int stack_size)
{
	int one_up;
	int two_down;

	one_up = stack_size - one->pos - 1;
	two_down = two->pos + 1;
	one->callback = action_item(one->pos, stack_size);
	two->callback = action_item(two->pos, stack_size);
	one->count = one_up;
	two->count = two_down;
	return (one_up < two_down ? one : two);
}

static int	lost_steps_to_up(int stack_size, int pos)
{
	int	up;
	int	down;

	up = stack_size - pos - 1;
	down = pos + 1;
	return (up < down ? up : down);
}

static int	skolko_vygodno(t_item *a, int stack_size, action do_hust, int count)
{	
	int	after_to_top;

	if (do_hust == a->callback)
		return (a->count);
	if (do_hust == rotate)
	{
		after_to_top = (a->pos + count) % stack_size;
		after_to_top = lost_steps_to_up(stack_size, after_to_top);
	}
	else if (do_hust == reverse_rotate)
	{
		after_to_top = (a->pos - count);
		if (after_to_top < 0)
			after_to_top = stack_size - after_to_top;
		after_to_top = lost_steps_to_up(stack_size, after_to_top);
	}
	return (a->count - after_to_top);
}

static void	rotate_r(stack *rotate)
{
	t_item	*prelast;

	prelast = NULL;
	prelast = rotate->head;
	if (rotate->stack_size < 2)
		return ;
	while (prelast->next && prelast->next != rotate->foots)
	{
		prelast = prelast->next;
	}
	prelast->next = NULL;
	rotate->foots->next = rotate->head;
	rotate->head = rotate->foots;
	rotate->foots = prelast;
	refresh_positions(rotate);
}

static void	reverse_rotate_r(stack *v_rotate)
{
	v_rotate->foots->next = v_rotate->head;
	v_rotate->foots = v_rotate->head;
	v_rotate->head = v_rotate->foots->next;
	v_rotate->foots->next = NULL;
	refresh_foots(v_rotate);
}

static void	insert_to_stack_b(t_item *itema, t_item *itemb, stack *a, stack *b)
{
	int		both;
	action	func;
	char	*act;

	func = itema->callback == reverse_rotate ? rotate_r : reverse_rotate_r;
	act = itema->callback == reverse_rotate ? "rrr" : "rr";
	both = skolko_vygodno(itemb, a->stack_size, itema->callback, itema->count);
	while (both > 0 && itema->pos < a->stack_size - 1)
	{
		func(a);
		func(b);
		printf("%s\n", act);
		both--;
	}
	while (itema->pos < a->stack_size - 1)
	{
		itema->callback(a);
	}
	itemb->callback = action_item(itemb->pos, b->stack_size);
	itemb->callback = lost_steps_to_up(b->stack_size, itemb->pos);
	while (itemb->count)
	{
		itemb->callback(b);
		itemb->count--;
	}
	push_to(a, a, b);
}

static void sort_in_ranges(range *current, stack *a, stack *b)
{
	t_item	*top;
	t_item	*bottom;
	t_item	*target;
	t_item	*from_b;

	top = 0;
	bottom = 0;
	target = 0;
	while ((top = find_first_position_int(current, a)))
	{
		bottom = find_last_position_int(current, a);
		target = choose_best_number(top, bottom, a->stack_size);
		from_b = find_best_position(target->value, b);
		insert_to_stack_b(target, from_b, a, b);
	}
	
}

static void		move_all_stack_b(sorter *sorter)
{
	int	i;
	int	current_range_size;
	range	*current_range;
	int		arr;

	current_range_size = sorter->ranges->ranges[0].size;
	i = 0;
	current_range = (sorter->ranges->ranges) + i;
	i = 0;
	arr = 0;
	range_pack_verbose(sorter);
	while (sorter->a->stack_size)
	{
		while (i < sorter->ranges->count_ranges)
		{
			sort_in_ranges(current_range + i, sorter->a, sorter->b);
			i++;
		}
		// current_range = (sorter->ranges->ranges) + i;
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

static void		sort_many_values_copy(sorter *s)
{
	s->ranges = range_pack_from_stack(s->a);
	move_all_stack_b(s);
	validate_stack(s->b);
	// push_all_to_a(s->a, sorter->b);
	print_stack(s->a[0]);
	print_stack(s->b[0]);
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
	
	// if (ac <= 2)
	// 	exit_program_with_err(NULL, NULL, CODE_ERROR);
	sorter = create_sorter();
	fill_stack(sorter->a, ac - 1, av + 1);
	refresh_positions(sorter->a);
	if (sorter->a->stack_size == 3)
	{
		sort_three_values(sorter->a);
	}
	else if (sorter->a->stack_size > 3 && sorter->a->stack_size <= 5)
	{
	}
	else
		sort_many_values_copy(sorter);
	print_stack(*(sorter->a));
	printf("Operations: %d\n", count_of_operations);
	return (0);
}
