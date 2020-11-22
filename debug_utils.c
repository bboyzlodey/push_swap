#include "push_swap.h"

void	print_stack(stack print)
{
	t_item	*tmp;
	int		position;

	position = 0;
	tmp = NULL;
	position = print.stack_size - 1;
	tmp = print.head;
	printf("stack %c head:\n", print.identifier);
	while (tmp)
	{
		printf("[value: %-30d, pos: %d]\n", tmp->value, position);
		position--;
		tmp = tmp->next;
	}
	printf("stack %c foots^^^^\n\n", print.identifier);
}

void range_pack_verbose(sorter *sorter)
{
	printf("size of ranges: %d\n", (sorter->ranges->count_ranges));
	int i = 0;
	while (i < (sorter->ranges->count_ranges))
	{
		int j = 0;
		while (j < sorter->ranges->ranges[i].size)
		{
			printf("range: %5d | item: %5d | value: %d\n", j, i, sorter->ranges->ranges[i].array[j]);
			j++;
		}
		i++;
	}
}
