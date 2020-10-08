#include "push_swap.h"

void	init_stack(stack to_init, int size, char identifier)
{
	to_init.identifier = identifier;
	to_init.stack_size = size;
	to_init.values = ft_memalloc(sizeof(int) * size);
	to_init.stack_values = 0;
}

void	fill_stack(stack to_fill, int ac, char **av)
{
	while (to_fill.stack_values < ac && av)
	{
		to_fill.values[to_fill.stack_values] = ft_atoi(av[to_fill.stack_values]);
		if (to_fill.stack_values[to_fill.values] == 0)
		{
			if (!(av[to_fill.stack_values][0] == "0" && av[to_fill.stack_values][1] == "\0"))
				exit_program_with_err(&to_fill, NULL, CODE_ERROR);

		}
		to_fill.stack_values;		
	}
}