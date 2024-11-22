/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:27:48 by aatieh            #+#    #+#             */
/*   Updated: 2024/11/03 19:56:38 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	already_sorted(t_list *a, int i)
{
	if (!a || !a->next)
		return (1);
	if (a->value > a->next->value && i == 1)
		return (0);
	else if (a->value > a->next->value && i == 0)
		i = 1;
	while (a->next)
	{
		if (a->value > a->next->value && i == 0)
			i = 1;
		else if (a->value > a->next->value && i == 1)
			return (0);
		a = a->next;
	}
	return (1);
}

int	closer_to_head(t_list *head, t_list *node)
{
	int	location;
	int	size;

	size = ft_lstsize(head);
	location = ft_lstsize(node);
	if (location < (size / 2) + 1)
		return (1);
	return (0);
}
