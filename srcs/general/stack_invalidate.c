/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_invalidate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 02:23:45 by asybil            #+#    #+#             */
/*   Updated: 2020/11/24 03:36:45 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	refresh_foots(t_stack *a)
{
	t_item	*tmp;

	tmp = 0;
	tmp = a->head;
	while (tmp && (tmp->next))
	{
		tmp = tmp->next;
	}
	a->foots = tmp;
}
