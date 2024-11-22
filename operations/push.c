/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:53:02 by aatieh            #+#    #+#             */
/*   Updated: 2024/11/03 20:08:40 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list **dest, t_list **src)
{
	t_list	*tmp;

	if (!(*src))
		return ;
	tmp = (*src)->next;
	ft_lstadd_front(dest, *src);
	*src = tmp;
}

void	pa(t_list **a_head, t_list **b_head, t_list **r_head)
{
	t_list	*new_node;

	push(a_head, b_head);
	new_node = ft_lstnew(ft_strdup("pa\n"));
	if (!new_node)
		return ;
	ft_lstadd_back(r_head, new_node);
}

void	pb(t_list **a_head, t_list **b_head, t_list **r_head)
{
	t_list	*new_node;

	push(b_head, a_head);
	new_node = ft_lstnew(ft_strdup("pb\n"));
	if (!new_node)
		return ;
	ft_lstadd_back(r_head, new_node);
}
