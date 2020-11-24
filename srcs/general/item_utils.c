/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asybil <asybil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:34:17 by asybil            #+#    #+#             */
/*   Updated: 2020/11/24 18:05:46 by asybil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	check_overflow(int number, char *str)
{
	char	*tmp;
	int		result;

	tmp = ft_itoa(number);
	result = ft_strcmp(tmp, str);
	ft_strdel(&tmp);
	return (result);
}

static int	additional_validation(char *valid)
{
	if (valid[0] == 0)
	{
		return (0);
	}
	else if (!ft_isdigit(*valid))
	{
		return (1);
	}
	return (additional_validation(valid + 1));
}

int			init_item(t_item *item, char *value)
{
	item->next = NULL;
	item->prev = NULL;
	item->value = 0;
	if (value == NULL || value[0] == '\0')
		return (-1);
	else if (additional_validation(value + (value[0] == '-' ? 1 : 0)))
	{
		return (-1);
	}
	item->value = ft_atoi(value);
	if (check_overflow((item->value), value))
	{
		return (-1);
	}
	return (0);
}

t_item		*item_from_int(int val)
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
	return (tmp);
}

t_item		*item_malloc(void)
{
	return (t_item*)ft_memalloc(sizeof(t_item));
}
