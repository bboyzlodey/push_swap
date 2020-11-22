/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 01:29:13 by asybil            #+#    #+#             */
/*   Updated: 2020/11/23 01:30:05 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	repeat(action func, int times, stack *arg)
{
	while (times)
	{
		func(arg);
		times--;
	}
}
