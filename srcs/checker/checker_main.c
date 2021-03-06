/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:34:38 by asybil            #+#    #+#             */
/*   Updated: 2020/11/25 00:57:02 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/get_next_line.h"

static void	check_result(t_stack *a, t_stack *b)
{
	if (b->stack_size != 0 || is_sorted_stack(a) < 0)
		exit_program_with_err(a, b, CODE_KO);
	exit_program_with_err(a, b, CODE_OK);
}

static void	checker_process(t_stack *a, t_stack *b)
{
	char		*line;
	t_stack		*choosed;
	t_action	func;

	line = 0;
	choosed = 0;
	func = 0;
	while (get_next_line(0, &line) > 0)
	{
		choosed = get_choosed_stack(a, b, line);
		func = get_action(line);
		if (func != NULL && choosed != NULL)
			func(choosed);
		else if (choosed == NULL && func != NULL)
		{
			func(a);
			func(b);
		}
		else if (choosed != NULL && line[0] == 'p')
			push_to(choosed, a, b);
		else
			exit_program_with_err(a, b, CODE_ERROR);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

int			main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	a = stack_malloc();
	b = stack_malloc();
	init_stack(a, 'a');
	init_stack(b, 'b');
	fill_stack(a, ac - 1, av + 1, b);
	checker_process(a, b);
	check_result(a, b);
	return (0);
}
