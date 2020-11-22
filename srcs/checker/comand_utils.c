/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 01:57:09 by asybil            #+#    #+#             */
/*   Updated: 2020/11/23 02:55:37 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/get_next_line.h"

static int	command_is_valid(char *s)
{
	int		result;

	result = 0;
	result = ft_strncmp(s, "pa", 2) | ft_strncmp(s, "pb", 2) | \
	ft_strncmp(s, "sa", 2) | ft_strncmp(s, "sb", 2) | ft_strncmp(s, "ss", 2) | \
	ft_strncmp(s, "ra", 2) | ft_strncmp(s, "rb", 2) | ft_strncmp(s, "rr", 2) | \
	ft_strncmp(s, "rra", 2) | ft_strncmp(s, "rrb", 2) | ft_strncmp(s, "rrr", 2);
	return (result);
}

stack		*get_choosed_stack(stack *a, stack *b, char *av)
{
	if (command_is_valid(av) == 0)
	{
		exit_program_with_err(a, b, CODE_ERROR);
	}
	if (av[1] == 'a' || av[2] == 'a')
		return (a);
	else if (av[1] == 'b' || av[2] == 'b')
		return (b);
	return (NULL);
}

action		get_action(char *av)
{
	if (av[0] == 's')
	{
		return (swap);
	}
	else if (av[0] == 'r')
	{
		if (av[1] == 'r')
			return (reverse_rotate);
		return (rotate);
	}
	return (NULL);
}
