#include "../push_swap.h"
#include "../libft/get_next_line.h"

static stack	*get_choosed_stack(stack *a, stack *b, char *av)
{
	if (ft_strlen(av) < 2)
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
	while (get_next_line(3, &line))
	{
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
	return 0;
}