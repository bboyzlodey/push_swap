/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_pack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.21-school.ru >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 02:08:27 by asybil            #+#    #+#             */
/*   Updated: 2020/10/28 02:33:47 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static range_pack	*range_pack_malloc(void)
{
	return (ft_memalloc(sizeof(range_pack)));
}

static int			range_values(int numbers)
{
	int	groups;

	groups = 1;
	groups = groups > 10 && groups <= 24 ? 3 : groups;
	groups = groups > 24 && groups <= 99 ? 4 : groups;
	groups = groups > 100 && groups <= 200 ? 5 : groups;
	groups = groups > 200 && groups <= 350 ? 7 : groups;
	groups = groups > 350 && groups < 700 ? 11 : groups;
	groups = groups > 700 && groups < 1000 ? 15 : groups;
	return (groups);
}



range_pack			*ft_new_range_pack(int count_values)
{
	int			count;
	range_pack	*new;

	new = NULL;
	new = range_pack_malloc();
	count = count_values;

	return (new);
}
