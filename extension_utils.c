#include "./push_swap.h"

void	repeat(action func, int times, stack *arg)
{
	while (times)
	{
		func(arg);
		times--;
	}
}

void	refresh_positions(t_stack *a)
{
	int		i;
	t_item	*tmp;

	i = a->stack_size - 1;
	tmp = a->head;
	while (i <= 0 && tmp)
	{
		tmp->pos = i;
		i--;
		tmp = tmp->next;
	}
}
