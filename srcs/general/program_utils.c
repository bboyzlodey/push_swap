/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 01:28:53 by asybil            #+#    #+#             */
/*   Updated: 2020/11/23 02:35:50 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
			to_free = ((void *)((clear->head)));
			ft_memdel(&to_free);
			clear->head = clear->foots;
		}
		to_free = ((void *)clear);
		ft_memdel(&to_free);
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
