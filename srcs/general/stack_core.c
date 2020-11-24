/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 02:12:06 by asybil            #+#    #+#             */
/*   Updated: 2020/11/24 02:23:56 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
	return (tmp);
}

stack	*stack_malloc(void)
{
	stack	*tmp;

	tmp = 0;
	tmp = ft_memalloc(sizeof(stack));
	return (tmp);
}
