/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:20:16 by aatieh            #+#    #+#             */
/*   Updated: 2024/11/03 20:00:10 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(char **res, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	trigger;
	int	count;

	count = 0;
	trigger = 0;
	i = 0;
	while (s[i])
	{
		if (trigger == 0 && s[i] != c)
		{
			count++;
			trigger = 1;
		}
		else if (s[i] == c)
			trigger = 0;
		i++;
	}
	return (count);
}

static char	*assign_word(char const *s, char c)
{
	char	*res;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int	assign_all(char const *s, char c, char ***res)
{
	int		i;
	int		j;
	int		trigger;

	i = 0;
	trigger = 0;
	j = 0;
	while (s[i])
	{
		if (trigger == 0 && s[i] != c)
		{
			res[0][j] = assign_word(&s[i], c);
			if (res[0][j] == NULL)
			{
				free_all (*res, j);
				return (0);
			}
			trigger = 1;
			j++;
		}
		else if (s[i] == c)
			trigger = 0;
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		word_num;

	word_num = count_words (s, c);
	if (!s)
		return (NULL);
	res = (char **)malloc (sizeof (char *) * (word_num + 1));
	if (!res)
		return (NULL);
	if (word_num == 0)
	{
		res[0] = NULL;
		return (res);
	}
	else if (assign_all(s, c, &res) == 0)
		return (NULL);
	res[word_num] = NULL;
	return (res);
}
