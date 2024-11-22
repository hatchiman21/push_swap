/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:52:40 by aatieh            #+#    #+#             */
/*   Updated: 2024/11/11 21:29:48 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	biggest_in_chunk(t_list *stack, int value, int chunk_size)
{
	t_list	*tmp;
	t_list	*smaller;
	t_list	*biggest;
	int		i;

	i = 0;
	biggest = get_biggest(stack);
	smaller = stack;
	while (i++ < chunk_size)
	{
		tmp = stack;
		smaller = biggest;
		while (tmp)
		{
			if (smaller->value > tmp->value && (tmp->value > value))
				smaller = tmp;
			tmp = tmp->next;
		}
		value = smaller->value;
	}
	return (value);
}

t_list	*separat_chunk(t_list **a, t_list **b,
				t_push_list *chunk, int chunk_size)
{
	int		i;
	t_list	*r;

	i = 0;
	r = NULL;
	while (i++ < chunk_size)
	{
		while (closest_elemnt(*a, chunk) == 1)
			ra(a, &r);
		while (closest_elemnt(*a, chunk) == 2)
			rra(a, &r);
		if ((*b) && (*a)->value > get_biggest(*b)->value)
			put_on_bottom(b, &r, get_smallest(*b)->value, 'b');
		else if (*b)
			put_on_bottom(b, &r, get_bigger(*b, (*a)->value)->value, 'b');
		pb(a, b, &r);
	}
	return (r);
}

static void	ft_sort_con(t_list **a, t_list **b, t_list **r, t_push_list *chunk)
{
	int	sorted;
	int	total_size;

	sorted = 0;
	total_size = ft_lstsize(*a);
	while (total_size > 5 && chunk->size > 0)
	{
		sorted += chunk->size;
		chunk->biggest = biggest_in_chunk(*a, chunk->smallest, chunk->size);
		ft_lstadd_back(r, separat_chunk(a, b, chunk, chunk->size));
		chunk->smallest = chunk->biggest;
		if (total_size - sorted <= chunk->size)
			chunk->size = total_size - sorted - 2;
	}
	if (total_size > 5)
		put_on_top(a, r, get_biggest(*a)->value, 'a');
	if (*b)
		put_on_bottom(b, r, get_smallest(*b)->value, 'b');
	while (*b)
		pa(a, b, r);
	put_on_top(a, r, get_smallest(*a)->value, 'a');
	free(chunk);
}

void	ft_sort(t_list **a, t_list **b, t_list **r)
{
	t_push_list	*chunk;
	int			total_size;

	total_size = ft_lstsize(*a);
	chunk = malloc(sizeof(t_push_list));
	if (!chunk)
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	if (total_size > 24 && total_size < 300)
		chunk->size = total_size / 6;
	else if (total_size >= 300)
		chunk->size = total_size / 12;
	else if (total_size <= 5)
		ft_sort_5(a, b, r, total_size);
	else
		chunk->size = total_size - 1;
	chunk->smallest = get_smallest(*a)->value;
	if (already_sorted(*a, 0))
		put_on_top(a, r, get_smallest(*a)->value, 'a');
	if (already_sorted(*a, 1))
		return (free(chunk));
	ft_sort_con(a, b, r, chunk);
}
