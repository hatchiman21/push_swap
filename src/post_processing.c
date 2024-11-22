/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 02:51:45 by aatieh            #+#    #+#             */
/*   Updated: 2024/11/03 20:26:11 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_clear_item(t_list **lst, t_list *node)
{
	t_list	*step;

	step = *lst;
	if (!node)
		return (NULL);
	while (step && step->next != node)
		step = step->next;
	if (!step)
		return (NULL);
	if (node->content)
		free(node->content);
	if (node == *lst)
		*lst = node->next;
	else
		step->next = node->next;
	free(node);
	return (NULL);
}

void	efficiency_check_rr(t_list **r)
{
	t_list	*tmp;
	t_list	*step;

	tmp = (*r)->next;
	while (tmp && tmp->next)
	{
		step = tmp->next;
		if (!ft_strncmp(tmp->content, "rra\n", 3)
			|| !ft_strncmp(tmp->content, "rrb\n", 3))
			while (step && step->next && !ft_strncmp(step->content, "rrr\n", 3))
				step = step->next;
		if ((ft_strncmp(tmp->content, "rra\n", 3) == 0
				&& ft_strncmp(step->content, "rrb\n", 3) == 0)
			|| (ft_strncmp(tmp->content, "rrb\n", 3) == 0
				&& ft_strncmp(step->content, "rra\n", 3) == 0))
		{
			free(tmp->content);
			tmp->content = ft_strdup("rrr\n");
			ft_clear_item(r, step);
			tmp = previous_node(*r, tmp);
		}
		else
			tmp = tmp->next;
	}
}

void	efficiency_check(t_list **r)
{
	t_list	*tmp;
	t_list	*step;

	tmp = (*r)->next;
	while (tmp && tmp->next)
	{
		step = tmp->next;
		if (!ft_strncmp(tmp->content, "ra\n", 3)
			|| !ft_strncmp(tmp->content, "rb\n", 3))
			while (step && step->next && !ft_strncmp(step->content, "rr\n", 3))
				step = step->next;
		if ((ft_strncmp(tmp->content, "ra\n", 3) == 0
				&& ft_strncmp(step->content, "rb\n", 3) == 0)
			|| (ft_strncmp(tmp->content, "rb\n", 3) == 0
				&& ft_strncmp(step->content, "ra\n", 3) == 0))
		{
			free(tmp->content);
			tmp->content = ft_strdup("rr\n");
			ft_clear_item(r, step);
			tmp = previous_node(*r, tmp);
		}
		else
			tmp = tmp->next;
	}
	efficiency_check_rr(r);
}
