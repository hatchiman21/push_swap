/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:27:44 by aatieh            #+#    #+#             */
/*   Updated: 2024/10/29 19:06:42 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*get_smallest(t_list *stack)
{
	t_list	*tmp;
	t_list	*smallest;

	smallest = stack;
	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (smallest->value > tmp->value)
				smallest = tmp;
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (smallest);
}

t_list	*get_bigger(t_list *stack, int value)
{
	t_list	*bigger;

	bigger = NULL;
	while (stack)
	{
		if (stack->value > value && (!bigger || stack->value < bigger->value))
			bigger = stack;
		stack = stack->next;
	}
	return (bigger);
}

t_list	*get_biggest(t_list *stack)
{
	t_list	*biggest;

	biggest = stack;
	while (stack)
	{
		if (biggest->value < stack->value)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}

t_list	*previous_node(t_list *head, t_list *node)
{
	if (head == node)
		return (ft_lstlast(head));
	while (head && head->next != node)
		head = head->next;
	return (head);
}

int	closest_elemnt(t_list *a, t_push_list *chunk)
{
	int		rotate;
	int		rev_rotate;
	t_list	*tmp;

	rotate = 0;
	rev_rotate = 0;
	tmp = a;
	while (tmp && !(tmp->value <= chunk->biggest
			&& tmp->value > chunk->smallest))
	{
		rotate++;
		tmp = tmp->next;
	}
	tmp = a;
	while (tmp && !(tmp->value <= chunk->biggest
			&& tmp->value > chunk->smallest))
	{
		tmp = previous_node(a, tmp);
		rev_rotate++;
	}
	if (rev_rotate == 0 || rotate == 0)
		return (3);
	if (rotate <= rev_rotate)
		return (1);
	return (2);
}
