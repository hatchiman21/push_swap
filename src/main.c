/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:52:51 by aatieh            #+#    #+#             */
/*   Updated: 2024/11/11 21:30:08 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	t_list	*result;
	int		error;

	a = NULL;
	b = NULL;
	result = NULL;
	error = error_check(argc, argv, &a);
	if (error == 1)
		return (free_stack(&a), error);
	if (error != 0)
		return (free_stack(&a), write(2, "Error\n", 7), error);
	ft_sort(&a, &b, &result);
	if (result && result->next)
		efficiency_check(&result);
	print_free_result(&result);
	free_stack(&a);
	return (0);
}
