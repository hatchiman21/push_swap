/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:53:10 by aatieh            #+#    #+#             */
/*   Updated: 2024/11/03 20:08:44 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_list **head)
{
	t_list	*tmp;

	if (!(*head) || !((*head)->next))
		return ;
	tmp = ft_lstlast(*head);
	tmp->next = *head;
	*head = (*head)->next;
	tmp->next->next = NULL;
}

void	ra(t_list **head, t_list **r_head)
{
	t_list	*new_node;

	rotate(head);
	new_node = ft_lstnew(ft_strdup("ra\n"));
	if (!new_node)
		return ;
	ft_lstadd_back(r_head, new_node);
}

void	rb(t_list **head, t_list **r_head)
{
	t_list	*new_node;

	rotate(head);
	new_node = ft_lstnew(ft_strdup("rb\n"));
	if (!new_node)
		return ;
	ft_lstadd_back(r_head, new_node);
}

void	rr(t_list **a_head, t_list **b_head, t_list **r_head)
{
	t_list	*new_node;

	rotate(a_head);
	rotate(b_head);
	new_node = ft_lstnew(ft_strdup("rr\n"));
	if (!new_node)
		return ;
	ft_lstadd_back(r_head, new_node);
}
