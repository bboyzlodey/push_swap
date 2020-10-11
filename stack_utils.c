#include "push_swap.h"

void	init_stack(stack *to_init, char identifier)
{
	to_init->identifier = identifier;
	to_init->stack_size = 0;
	to_init->head = NULL;
	to_init->foots = NULL;
}

void	fill_stack(stack *to_fill, int ac, char **av)
{
	if (av == NULL || *av == NULL || ac == 0)
		return ;
	else if ((to_fill->head = item_malloc()) == NULL)
	{
		exit_program_with_err(to_fill, NULL, CODE_MEMMORY_ERROR);
	}
	else if (init_item(to_fill, av[to_fill->stack_size]) < 0)
		exit_program_with_err(to_fill, NULL, CODE_ERROR);
	to_fill->foots = to_fill->head;
	to_fill->stack_size++;
	while (to_fill->stack_size < ac && (to_fill->foots->next = item_malloc()) != 0 /*NULL*/)
	{
		to_fill->foots = to_fill->foots->next;
		if (init_item(to_fill->foots, av[to_fill->stack_size]) < 0)
		{
			exit_program_with_err(to_fill, NULL, CODE_ERROR);
		}
		to_fill->stack_size++;
	}
}