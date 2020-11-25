/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:34:05 by asybil            #+#    #+#             */
/*   Updated: 2020/11/24 03:38:02 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_stack *swap)
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
	else
		exit_program_with_err(swap, NULL, CODE_KO);
	if (PS_VERBOSE == 1)
		ft_printf("s%c\n", (swap->identifier));
}

void	rotate(t_stack *rotate)
{
	t_item	*prelast;

	prelast = NULL;
	prelast = rotate->head;
	if (rotate->stack_size < 2)
		exit_program_with_err(rotate, NULL, CODE_KO);
	while (prelast->next && prelast->next != rotate->foots)
	{
		prelast = prelast->next;
	}
	prelast->next = NULL;
	rotate->foots->next = rotate->head;
	rotate->head = rotate->foots;
	rotate->foots = prelast;
	refresh_foots(rotate);
	if (PS_VERBOSE == 1)
		ft_printf("rr%c\n", (rotate->identifier));
}

void	reverse_rotate(t_stack *v_rotate)
{
	if (v_rotate->stack_size < 2)
	{
		exit_program_with_err(v_rotate, NULL, CODE_KO);
	}
	refresh_foots(v_rotate);
	v_rotate->foots->next = v_rotate->head;
	v_rotate->foots = v_rotate->head;
	v_rotate->head = v_rotate->foots->next;
	v_rotate->foots->next = NULL;
	if (PS_VERBOSE == 1)
		ft_printf("r%c\n", (v_rotate->identifier));
}

void	push_to(t_stack *from, t_stack *a, t_stack *b)
{
	t_stack	*to;

	to = NULL;
	if (from && from->stack_size == 0)
	{
		exit_program_with_err(from, a, CODE_KO);
	}
	to = from == a ? b : a;
	push(to, pop(from));
	if (PS_VERBOSE == 1 && to != NULL)
		ft_printf("p%c\n", (to->identifier));
}
