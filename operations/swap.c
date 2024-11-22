/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:53:36 by aatieh            #+#    #+#             */
/*   Updated: 2024/11/03 20:08:45 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **head)
{
	t_list	*first_node;

	if (!(*head) || !((*head)->next))
		return ;
	first_node = *head;
	*head = first_node->next;
	first_node->next = (*head)->next;
	(*head)->next = first_node;
}

void	sa(t_list **head, t_list **r_head)
{
	t_list	*new_node;

	swap(head);
	new_node = ft_lstnew(ft_strdup("sa\n"));
	if (!new_node)
		return ;
	ft_lstadd_back(r_head, new_node);
}

void	sb(t_list **head, t_list **r_head)
{
	t_list	*new_node;

	swap(head);
	new_node = ft_lstnew(ft_strdup("sb\n"));
	if (!new_node)
		return ;
	ft_lstadd_back(r_head, new_node);
}

void	ss(t_list **a_head, t_list **b_head, t_list **r_head)
{
	t_list	*new_node;

	swap(a_head);
	swap(b_head);
	new_node = ft_lstnew(ft_strdup("ss\n"));
	if (!new_node)
		return ;
	ft_lstadd_back(r_head, new_node);
}
