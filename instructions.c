#include "push_swap.h"

void	push(stack from, stack to)
{

}

void	swap(stack swap)
{
	int	*tmp;

	tmp = NULL;
	if (swap.stack_values > 1)
	{
		tmp = swap.values + swap.stack_values - 1;
		swap.values[swap.stack_values - 1] = swap.values[swap.stack_values - 2];
		swap.values[swap.stack_values - 2] = tmp;
	}
	
}

void	rotate(stack rotate)
{
	int	*tmp;

	tmp = NULL;
	if (rotate.stack_values > 2)
	{

	}
}

void	reverse_rotate(stack rev_rotate)
{
	
}