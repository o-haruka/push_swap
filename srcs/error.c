/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:52:44 by homura            #+#    #+#             */
/*   Updated: 2025/11/08 17:56:30 by homura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

// II. プログラムにおけるエラー処理 (VI.3)
// push_swapプログラムには、引数の検証に関する厳格なエラー処理要件があります。
// • エラー発生時の出力：エラーが発生した場合、標準エラーに**"Error"とそれに続く’\n’**を表示しなければなりません。
// • エラーの例：エラーには、例えば以下のものが含まれます。
//     ◦ 引数の一部が整数ではない場合。
//     ◦ 引数の一部が整数（integer）の制限を超えている場合。
//     ◦ 重複が存在する場合。
// • 引数がない場合の動作：パラメーターが指定されていない場合、プログラムは何も表示せず、プロンプトに戻る必要があります。
// • 不正な引数入力の例：./push_swap 0 one 2 3を実行した場合、Errorと表示されます。
// • ソートの失敗：プログラムが表示する命令リストが長すぎる場合、または数字が適切にソートされていない場合、成績は0点となります。

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

//====================================================================
// argv[1]（コマンドライン引数の1つめ）をスペースで分割し、split に格納。
// 例: "12 34 56" → ["12", "34", "56"]
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
		if (ft_isint(split[i]) == 0)
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
		if (ft_isint(argv[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_isstrspace(argv[1]) == 1)
			return (1);
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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
