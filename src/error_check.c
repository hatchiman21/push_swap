/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:36:53 by aatieh            #+#    #+#             */
/*   Updated: 2024/11/03 20:18:54 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	print_free_result(t_list **r)
{
	t_list	*tmp;

	tmp = *r;
	while (tmp)
	{
		ft_printf("%s", (char *)tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(r, free);
}

int	check_duplicat(t_list **a_head)
{
	t_list	*tmp;
	t_list	*a;

	a = *a_head;
	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->value == tmp->value)
				return (free_stack(a_head), 1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

int	error_check(int argc, char *argv[], t_list **a)
{
	int		i;
	int		j;

	j = 1;
	if (argc == 1)
		return (1);
	while (j < argc)
	{
		i = 0;
		if (argv[j][i] == '\0')
			return (5);
		while (argv[j][i] && ((ft_isdigit(argv[j][i])
				|| argv[j][i] == '-' || argv[j][i] == '+')
				|| argv[j][i] == ' '))
			i++;
		if (argv[j][i] != '\0')
			return (2);
		if (grab_stack(argv[j++], a) != 0)
			return (3);
	}
	if (check_duplicat(a) != 0)
		return (4);
	return (0);
}
