#include "push_swap.h"

static void	free_stack(stack *clear)
{
	void	*to_free;

	to_free = NULL;
	if (clear != NULL)
	{
		clear->foots = NULL;
		while (clear->head)
		{
			clear->foots = clear->head->next;
			to_free = ((void *) ((clear->head)));
			ft_memdel(&to_free);
			clear->head = clear->foots;
		}
		to_free = ((void *)clear);
		// ft_memdel((void **)(&clear));
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
	ft_putchar('\n');
	exit(code);	
}
