/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:34:05 by asybil            #+#    #+#             */
/*   Updated: 2020/11/26 23:01:46 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(stack *swap)
{
	t_item *bellow_top;

	bellow_top = NULL;
	if (swap->stack_size > 2)
	{
		bellow_top = swap->head->next;
		swap->head->next = bellow_top->next;
		bellow_top->next = swap->head;
		swap->head = bellow_top;
	}
	else if (swap->stack_size == 2)
	{
		swap->foots = swap->head;
		swap->head = swap->foots->next;
		swap->head->next = swap->foots;
		swap->foots->next = NULL;
	}
	refresh_positions(swap);
	if (PS_VERBOSE == 1)
	{
		// TODO Use ft_printf
		ft_putchar('s');
		ft_putchar(swap->identifier);
		ft_putchar('\n');
	}
}

void	rotate(stack *rotate)
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
	if (PS_VERBOSE == 1)
	{
		// TODO Use ft_printf
		ft_putchar('r');
		ft_putchar(rotate->identifier);
		ft_putchar('\n');
	}
}

void	reverse_rotate(stack *v_rotate)
{
	v_rotate->foots->next = v_rotate->head;
	v_rotate->foots = v_rotate->head;
	v_rotate->head = v_rotate->foots->next;
	v_rotate->foots->next = NULL;
	// refresh_foots(v_rotate);
	if (PS_VERBOSE == 1)
	{
		// TODO Use ft_printf
		ft_putstr("rr");
		ft_putchar(v_rotate->identifier);
		ft_putchar('\n');
	}
}


void		push_to(stack *from, stack *a, stack *b)
{
	stack	*to;

	to = NULL;
	to = from == a ? b : a;
	push(to, pop(from));
	if (PS_VERBOSE == 1 && to != NULL)
	{
		// TODO Use ft_printf
		ft_putchar('p');
		ft_putchar(to->identifier);
		ft_putchar('\n');
	}
}
