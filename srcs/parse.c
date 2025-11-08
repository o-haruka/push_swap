/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:08:18 by homura            #+#    #+#             */
/*   Updated: 2025/11/08 18:24:25 by homura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>

static int	get_split_size(char **split)
{
	int	size;

	size = 0;
	while (split[size])
		size++;
	return (size);
}

static int	convert_split_to_array(char **split, int **arr, int size)
{
	int	i;

	*arr = malloc(sizeof(int) * size);
	if (!*arr)
		return (1);
	i = 0;
	while (i < size)
	{
		(*arr)[i] = ft_atoi(split[i]);
		i++;
	}
	return (0);
}

static int	parse_args_split(char *arg, int **arr, int *size)
{
	char	**split;

	split = ft_split(arg, ' ');
	if (!split)
		return (1);
	*size = get_split_size(split);
	if (*size == 0 || convert_split_to_array(split, arr, *size) == 1)
	{
		if (*size > 0)
			free(*arr);
		free_split_array(split);
		return (1);
	}
	free_split_array(split);
	return (0);
}

int	parse_args(int argc, char **argv, int **arr, int *size)
{
	int	i;

	if (argc == 2)
		return (parse_args_split(argv[1], arr, size));
	*size = argc - 1;
	*arr = malloc(sizeof(int) * (*size));
	if (!*arr)
		return (1);
	i = 0;
	while (i < *size)
	{
		(*arr)[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (0);
}
