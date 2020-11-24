/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 02:12:06 by asybil            #+#    #+#             */
/*   Updated: 2020/11/24 03:41:09 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_stack *push, t_item *item)
{
	item->next = push->head;
	push->head = item;
	push->stack_size++;
	refresh_foots(push);
}

t_item	*pop(t_stack *pop)
{
	t_item	*tmp;

	tmp = NULL;
	tmp = pop->head;
	pop->head = pop->head->next;
	tmp->next = NULL;
	tmp->prev = NULL;
	pop->stack_size--;
	refresh_foots(pop);
	return (tmp);
}

t_stack	*stack_malloc(void)
{
	t_stack	*tmp;

	tmp = 0;
	tmp = ft_memalloc(sizeof(t_stack));
	return (tmp);
}
