#include "push_swap.h"

void	print_stack(stack print)
{
	t_item	*tmp;
	int		position;

	position = 0;
	tmp = NULL;
	position = print.stack_size - 1;
	tmp = print.head;
	printf("stack %c head:", print.identifier);
	while (tmp)
	{
		printf("[value: %d, pos: %d]");
		position--;
		tmp = tmp->next;
	}
	printf("stack %c foots^^^^", print.identifier);
}