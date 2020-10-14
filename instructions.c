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

void	rotate(stack *rotate)
{
	t_item	*prelast;

	prelast = NULL;
	prelast = rotate->head;
	while (prelast->next && prelast->next != rotate->foots)
	{
		prelast = prelast->next;
	}
	prelast->next = NULL;
	rotate->foots->next = rotate->head;
	rotate->head = rotate->foots;
	rotate->foots = prelast;
}

void	reverse_rotate(stack *v_rotate)
{
	v_rotate->foots->next = v_rotate->head;
	v_rotate->foots = v_rotate->head;
	v_rotate->head = v_rotate->foots->next;
	v_rotate->foots->next = NULL;
}