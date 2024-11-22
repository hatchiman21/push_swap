/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:27:50 by aatieh            #+#    #+#             */
/*   Updated: 2024/11/03 20:08:49 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_3(t_list **a, t_list **r, int size)
{
	t_list	*biggest;
	t_list	*smallest;

	biggest = get_biggest(*a);
	smallest = get_smallest(*a);
	if (size < 3)
		return ;
	else if (already_sorted(*a, 1) || (smallest == (*a)->next && biggest == *a)
		|| (smallest == ft_lstlast(*a) && biggest == (*a)->next))
		return ;
	else if (smallest != *a && biggest == ft_lstlast(*a))
		sa(a, r);
	else if (smallest == ft_lstlast(*a) && biggest == *a)
	{
		sa(a, r);
		rra(a, r);
	}
	else
	{
		rra(a, r);
		sa(a, r);
	}
}

void	ft_sort_5(t_list **a, t_list **b, t_list **r, int size)
{
	if (size >= 4)
	{
		put_on_top(a, r, get_smallest(*a)->value, 'a');
		if (already_sorted(*a, 1))
			return ;
		if (size == 5)
			pb(a, b, r);
		put_on_top(a, r, get_smallest(*a)->value, 'a');
		pb(a, b, r);
		put_on_top(a, r, get_smallest(*a)->value, 'a');
		ft_sort_3(a, r, size);
	}
	else if (size < 4)
	{
		ft_sort_3(a, r, size);
		put_on_top(a, r, get_smallest(*a)->value, 'a');
	}
	while (*b)
		pa(a, b, r);
}
