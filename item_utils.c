#include "push_swap.h"

int		init_item(t_item *item, char *value)
{
	item->next = NULL;
	item->prev = NULL;
	item->value = 0;
	if (value == NULL || value[0] == '\0')
		return -1;
	else if ((item->value = ft_atoi(value)) == 0 && value[0] == '0' && value[1] != '\0' || (value[0] != '0' && item->value == 0))
	{
		return -1;
	}
	return 0;	
}

t_item	*item_from_int(int val)
{
	t_item	*tmp;

	tmp = NULL;
	tmp = item_malloc();
	if (tmp)
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		tmp->value = val;
	}
	return tmp;
}

t_item	*item_malloc(void)
{
	return (t_item*)ft_memalloc(sizeof(t_item));
}