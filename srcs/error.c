/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:52:44 by homura            #+#    #+#             */
/*   Updated: 2025/11/13 20:56:57 by homura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	check_one_commandline(char **argv)
{
	int		i;
	int		flag;
	char	**split;

	i = 0;
	flag = 0;
	split = ft_split(argv[1], ' ');
	while (split[i] != NULL)
	{
		if (ft_isint(split[i]) == FALSE)
			flag++;
		i++;
	}
	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
	if (flag > 0)
		return (1);
	return (0);
}

static int	check_many_commandlines(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_isint(argv[i]) == FALSE)
			return (ERROR);
		i++;
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_isstrspace(argv[1]))
			return (ERROR);
		return (check_one_commandline(argv));
	}
	else
		return (check_many_commandlines(argv));
}

int	check_duplicate(int *args, size_t counter)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < counter)
	{
		j = i + 1;
		while (j < counter)
		{
			if (args[i] == args[j])
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
