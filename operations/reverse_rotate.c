/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:53:23 by aatieh            #+#    #+#             */
/*   Updated: 2024/11/03 20:08:42 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_list **head)
{
	t_list	*tmp;

	if (!(*head) || !((*head)->next))
		return ;
	tmp = ft_lstlast(*head);
	tmp->next = *head;
	*head = tmp;
	while (tmp->next != *head)
		tmp = tmp->next;
	tmp->next = NULL;
}

void	rra(t_list **head, t_list **r_head)
{
	t_list	*new_node;

	reverse_rotate(head);
	new_node = ft_lstnew(ft_strdup("rra\n"));
	if (!new_node)
		return ;
	ft_lstadd_back(r_head, new_node);
}

void	rrb(t_list **head, t_list **r_head)
{
	t_list	*new_node;

	reverse_rotate(head);
	new_node = ft_lstnew(ft_strdup("rrb\n"));
	if (!new_node)
		return ;
	ft_lstadd_back(r_head, new_node);
}

void	rrr(t_list **a_head, t_list **b_head, t_list **r_head)
{
	t_list	*new_node;

	reverse_rotate(a_head);
	reverse_rotate(b_head);
	new_node = ft_lstnew(ft_strdup("rrr\n"));
	if (!new_node)
		return ;
	ft_lstadd_back(r_head, new_node);
}
