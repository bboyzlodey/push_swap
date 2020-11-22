/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:33:22 by asybil            #+#    #+#             */
/*   Updated: 2020/11/23 01:39:32 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Recursion search
**	return value: 0 - if stack sorted, -1 - else
*/
static	int	r_is_sorted(t_item *current, int next_val)
{
	if (current->value > next_val)
		return (-1);
	else if (current->next == NULL || current->next->next == NULL)
		return (0);
	return (r_is_sorted(current->next, current->next->next->value));
}

void	init_stack(stack *to_init, char identifier)
{
	to_init->identifier = identifier;
	to_init->stack_size = 0;
	to_init->head = NULL;
	to_init->foots = NULL;
}

void	fill_stack(stack *to_fill, int ac, char **av)
{
	if (av == NULL || *av == NULL || ac == 0)
		return ;
	else if ((to_fill->head = item_malloc()) == NULL)
	{
		exit_program_with_err(to_fill, NULL, CODE_MEMMORY_ERROR);
	}
	else if (init_item(to_fill->head, av[to_fill->stack_size]) < 0)
		exit_program_with_err(to_fill, NULL, CODE_ERROR);
	to_fill->foots = to_fill->head;
	to_fill->stack_size++;
	while (to_fill->stack_size < ac && (to_fill->foots->next = item_malloc()) != NULL /*NULL*/)
	{
		to_fill->foots = to_fill->foots->next;
		if (init_item(to_fill->foots, av[to_fill->stack_size]) < 0)
		{
			exit_program_with_err(to_fill, NULL, CODE_ERROR);
		}
		to_fill->stack_size++;
	}
}

/*
*	int		is_sorted_stack(stack sorted);
*	return value: 0 - if stack sorted, -1 - else
*/
int		is_sorted_stack(stack *sorted)
{
	if (sorted->head == NULL || sorted->head->next == NULL)
		return (0);	
	return (r_is_sorted(sorted->head, sorted->head->next->value));
}

void	refresh_foots(stack *stack)
{
	t_item	*tmp;

	tmp = stack->head;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
	}
	stack->foots = tmp;
}

void	push(stack *push, t_item *item)
{
	item->next = push->head;
	push->head = item;
	push->stack_size++;
	refresh_foots(push);
}

t_item	*pop(stack *pop)
{
	t_item	*tmp;

	tmp = NULL;
	tmp = pop->head;
	pop->head = pop->head->next;
	tmp->next = NULL;
	tmp->prev = NULL;
	pop->stack_size--;
	refresh_foots(pop);
	return tmp;
}

stack	*stack_malloc(void)
{
	return ft_memalloc(sizeof(stack));
}