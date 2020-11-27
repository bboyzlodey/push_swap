/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:34:17 by asybil            #+#    #+#             */
/*   Updated: 2020/11/26 02:32:18 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int			init_item(t_item *item, char *value)
{
	char	*num_str;
	int		result;

	item->value = ft_atoi(value);
	num_str = ft_itoa(item->value);
	result = ft_strcmp(value, num_str);
	ft_strdel(&num_str);
	return (0);
}

t_item		*item_from_int(int val)
{
	t_item	*tmp;

	tmp = NULL;
	tmp = item_malloc();
	if (tmp)
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		tmp->value = val;
	}
	return (tmp);
}

t_item		*item_malloc(void)
{
	return (t_item*)ft_memalloc(sizeof(t_item));
}
