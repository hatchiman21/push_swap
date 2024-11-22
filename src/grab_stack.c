/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:18:18 by aatieh            #+#    #+#             */
/*   Updated: 2024/11/04 19:32:08 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	too_long(char *arg)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!ft_isdigit(arg[i]))
		return (2);
	while (arg[i] == '0')
		i++;
	while (ft_isdigit(arg[i]))
	{
		i++;
		count++;
	}
	if (count > 10)
		return (1);
	return (0);
}

int	assgin_nod(t_list **a, char *arg)
{
	t_list		*tmp;
	long int	value;

	tmp = NULL;
	tmp = malloc(sizeof(t_list));
	if (!tmp)
		return (1);
	value = ft_atoi(arg);
	tmp->value = value;
	tmp->next = NULL;
	ft_lstadd_back(a, tmp);
	if (value > INT_MAX || value < INT_MIN || too_long(arg))
		return (2);
	return (0);
}

int	grab_stack(char *arg, t_list **a)
{
	int		i;
	int		trigger;

	i = 0;
	trigger = 0;
	while (arg[i])
	{
		if (!(ft_isdigit(arg[i]) || arg[i] == ' '
				|| arg[i] == '-' || arg[i] == '+'))
			return (1);
		if (trigger == 0 && (ft_isdigit(arg[i])
				|| arg[i] == '-' || arg[i] == '+'))
		{
			if (assgin_nod(a, (arg + i)) != 0)
				return (2);
			trigger = 1;
		}
		else if (!(ft_isdigit(arg[i]) || arg[i] == '-' || arg[i] == '+'))
			trigger = 0;
		i++;
	}
	return (0);
}
