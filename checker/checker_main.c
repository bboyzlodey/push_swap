/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.21-school.ru >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:34:38 by asybil            #+#    #+#             */
/*   Updated: 2020/10/28 01:34:40 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/get_next_line.h"

static int		command_is_valid(char *s)
{
	int		result;

	result = 0;
	result = ft_strncmp(s, "pa", 2) | ft_strncmp(s, "pb", 2) | \
	ft_strncmp(s, "sa", 2) | ft_strncmp(s, "sb", 2) | ft_strncmp(s, "ss", 2) | \
	ft_strncmp(s, "ra", 2) | ft_strncmp(s, "rb", 2) | ft_strncmp(s, "rr", 2) | \
	ft_strncmp(s, "rra", 2) | ft_strncmp(s, "rrb", 2) | ft_strncmp(s, "rrr", 2);
	return (result);
}

static stack	*get_choosed_stack(stack *a, stack *b, char *av)
{
	if (command_is_valid(av) == 0)
	{
		exit_program_with_err(a, b, CODE_ERROR);
	}
	if (av[1] == 'a' || av[2] == 'a')
		return a;
	else if (av[1] == 'b' || av[2] == 'b')
		return b;
	return NULL;
}

static action	get_action(char *av)
{
	if (av[0] == 's')
	{
		return swap;
	}
	else if (av[0] == 'r')
	{
		if (av[1] == 'r')
			return reverse_rotate;
		return rotate;
	}
	return NULL;
}

static void		push_to(stack *from, stack *a, stack *b)
{
	stack	*to;

	to = NULL;
	to = from == a ? b : a;
	push(to, pop(from));
}

static void		check_result(stack *a, stack *b)
{
	if (b->stack_size != 0 || is_sorted_stack(a) < 0)
		exit_program_with_err(a, b, CODE_KO);
	exit_program_with_err(a, b, CODE_OK);
}

static void		checker_process(stack *a, stack *b)
{
	char	*line;
	stack	*choosed;
	action	func;

	line = NULL;
	func = NULL;

	int gnl = 0;
	while ( gnl = get_next_line(2, &line))
	{
		printf("\t%d comand: %s | %d\n",gnl, line, ft_strlen(line));
		if (ft_strcmp(line, "print") == 0)
		{
			print_stack(*a);
			print_stack(*b);
			continue ;
		}
		choosed = get_choosed_stack(a, b, line);
		func = get_action(line);
		if (func != NULL && choosed != NULL)
			func(choosed);
		else if (choosed == NULL)
		{
			func(a);
			func(b);
		}
		else if (choosed != NULL && line[0] == 'p')
			push_to(choosed, a, b);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	check_result(a, b);
}

int				main(int ac, char **av)
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
	checker_process(a, b);
	return 0;
}