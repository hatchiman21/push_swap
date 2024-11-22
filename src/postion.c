/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postion.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:27:46 by aatieh            #+#    #+#             */
/*   Updated: 2024/11/03 19:56:37 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	put_on_top(t_list **stack, t_list **r, int node_value, char s)
{
	int		i;
	t_list	*node;

	node = *stack;
	while (node && node->value != node_value)
		node = node->next;
	if (!node)
		return ;
	i = closer_to_head(*stack, node);
	while (i == 0 && node != *stack && s == 'a')
		ra(stack, r);
	while (i == 1 && node != *stack && s == 'a')
		rra(stack, r);
	while (i == 0 && node != *stack && s == 'b')
		rb(stack, r);
	while (i == 1 && node != *stack && s == 'b')
		rrb(stack, r);
}

void	put_on_bottom(t_list **stack, t_list **r, int node_value, char s)
{
	int		i;
	t_list	*node;

	node = *stack;
	while (node->value != node_value)
		node = node->next;
	i = closer_to_head(*stack, node);
	while (i == 0 && node != ft_lstlast(*stack) && s == 'a')
		ra(stack, r);
	while (i == 1 && node != ft_lstlast(*stack) && s == 'a')
		rra(stack, r);
	while (i == 0 && node != ft_lstlast(*stack) && s == 'b')
		rb(stack, r);
	while (i == 1 && node != ft_lstlast(*stack) && s == 'b')
		rrb(stack, r);
}
