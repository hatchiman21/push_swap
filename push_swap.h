/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 04:55:50 by aatieh            #+#    #+#             */
/*   Updated: 2024/11/03 19:56:39 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>

typedef struct s_push_swap
{
	void	*content;
	int		biggest;
	int		smallest;
	int		size;
}	t_push_list;

void	ra(t_list **head, t_list **r_head);
void	rb(t_list **head, t_list **r_head);
void	rr(t_list **a_head, t_list **b_head, t_list **r_head);

void	rra(t_list **head, t_list **r_head);
void	rrb(t_list **head, t_list **r_head);
void	rrr(t_list **a_head, t_list **b_head, t_list **r_head);

void	sa(t_list **head, t_list **r_head);
void	sb(t_list **head, t_list **r_head);
void	ss(t_list **a_head, t_list **b_head, t_list **r_head);

void	pa(t_list **a_head, t_list **b_head, t_list **r_head);
void	pb(t_list **a_head, t_list **b_head, t_list **r_head);

t_list	*previous_node(t_list *head, t_list *node);
t_list	*get_smallest(t_list *stack);
t_list	*get_bigger(t_list *stack, int value);
t_list	*get_biggest(t_list *stack);

int		already_sorted(t_list *a, int i);
int		closer_to_head(t_list *head, t_list *node);
int		closest_elemnt(t_list *a, t_push_list *chunk);

void	put_on_top(t_list **stack, t_list **r, int node_value, char s);
void	put_on_bottom(t_list **stack, t_list **r, int node_value, char s);
void	efficiency_check(t_list **r);
void	free_stack(t_list **stack);
void	print_free_result(t_list **r);

int		grab_stack(char *arg, t_list **a);
int		check_duplicat(t_list **a_head);
int		error_check(int argc, char *argv[], t_list **a);

void	ft_sort_5(t_list **a, t_list **b, t_list **r, int size);
void	ft_sort(t_list **a, t_list **b, t_list **r);

#endif
