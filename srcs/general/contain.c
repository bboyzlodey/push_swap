/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:23:03 by asybil            #+#    #+#             */
/*   Updated: 2020/11/25 00:31:34 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	contain(int number, t_stack *s)
{
	t_item	*tmp;

	tmp = NULL;
	tmp = s->head;
	while (tmp->next)
	{
		if (tmp->value == number)
		{
			return (-1);
		}
		tmp = tmp->next;
	}
	return (0);
}
