/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.21-school.ru >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:36:00 by asybil            #+#    #+#             */
/*   Updated: 2020/10/28 02:08:10 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static range	*range_malloc(void)
{
	return (ft_memalloc(sizeof(range)));
}

range			*ft_find_min_max(stack *a, stack *b)
{
	range	*new;
	t_item	*tmp;

	new = NULL;
	tmp = NULL;
	if ((new = range_malloc()) == NULL)
	{
		exit_program_with_err(a, b, CODE_MEMMORY_ERROR);
	}
	tmp = a->head;
	while (tmp)
	{
		if (new->from > tmp->value)
			new->from = tmp->value;
		else if (new->to < tmp->value)
			new->to = tmp->value;
		tmp = tmp->next;
	}
	return new;
}
