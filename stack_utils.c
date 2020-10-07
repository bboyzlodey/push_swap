#include "push_swap.h"

void	init_stack(stack to_init, int size, char identifier)
{
	to_init.identifier = identifier;
	to_init.stack_size = size;
	to_init.stack_values = NULL;
	to_init.stack_values = ft_memalloc(sizeof(int) * size);
	to_init.stack_values = 0;
}

void	fill_stack(stack to_fill, int ac, char **av)
{
	while (to_fill.stack_values > ac)
	{
		
	}
}