#include "push_swap.h"

static void	free_stack(stack *clear)
{
	if (clear != NULL)
	{
		clear->foots = NULL;
		while (clear->head)
		{
			clear->foots = clear->head->next;
			ft_memdel(&(clear->head));
			clear->head = clear->foots;
		}
		ft_memdel(&(clear));
	}
}

void		exit_program_with_err(stack *a, stack *b, exit_code code)
{
	char	*message;

	message = NULL;
	free_stack(a);
	free_stack(b);
	if (code == CODE_OK)
	{
		message = "OK";
	}
	else if (code == CODE_KO)
	{
		message = "KO";
	}
	else if (code == CODE_ERROR)
	{
		message = "Error";
	}
	ft_putstr(message);
	exit(code);	
}
