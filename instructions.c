#include "push_swap.h"

void	push(stack from, stack to)
{

}

void	swap(stack swap)
{
	int	*first;
	int *second;

	first = NULL;
	second = NULL;
	if (swap.stack_values > 1)
	{
		first = swap.values[swap.stack_values - 1];
		second = swap.values[swap.stack_values - 2];
		swap_ints(first, second);
	}
	
}

void	rotate(stack rotate)
{
	int	tmp;
	int	count;

	tmp = NULL;
	count = rotate.stack_values - 1;
	while (count > 0)
	{
		
		count--;
	}
	if (rotate.stack_values > 2)
	{

	}
}

void	reverse_rotate(stack v_rotate)
{
	
}