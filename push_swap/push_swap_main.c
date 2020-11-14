/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.21-school.ru >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:33:36 by asybil            #+#    #+#             */
/*   Updated: 2020/10/28 01:34:55 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	stack	*a;
	stack	*b;
	
	a = NULL;
	if (ac <= 2)
		exit_program_with_err(NULL, NULL, CODE_ERROR);
	a = stack_malloc();
	b = stack_malloc();
	init_stack(a, 'a');
	init_stack(b, 'b');
	fill_stack(a, ac - 1, av + 1);
	return (0);
}
