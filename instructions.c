#include "push_swap.h"

// void	push(stack from, stack to)
// {

// }

void	swap(stack *swap)
{
	t_item *bellow_top;

	bellow_top = NULL;
	if (swap->stack_size > 1)
	{
		bellow_top = swap->head->next;
		swap->head->next = bellow_top->next;
		bellow_top->next = swap->head;
		swap->head = bellow_top;
	}
}

// void	rotate(stack rotate)
// {
// 	// int	tmp;
// 	// int	count;

// 	// tmp = NULL;
// 	// count = rotate.stack_values - 1;
// 	// while (count > 0)
// 	// {

// 	// 	count--;
// 	// }
// 	// if (rotate.stack_values > 2)
// 	// {

// 	// }
// }

// void	reverse_rotate(stack v_rotate)
// {
	
// }