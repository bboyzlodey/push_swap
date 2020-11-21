/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.21-school.ru >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:29:04 by asybil            #+#    #+#             */
/*   Updated: 2020/11/22 01:56:28 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static sorter	*sorter_malloc(void)
{
	return ft_memalloc(sizeof(sorter));
}

sorter	*new_sorter(stack *a, stack *b)
{
	sorter	*new;

	new = NULL;
	if ((new = sorter_malloc()) == NULL)
	{
		exit_program_with_err(a, b, CODE_MEMMORY_ERROR);
	}
	new->a = a;
	new->b = b;
	new->ranges = range_pack_from_stack(a);
	return new;
}