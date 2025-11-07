#include "../includes/libft.h"
// #include "../includes/ft_stdlib.h"
#include "../includes/ft_string.h"

// 有効な整数かチェック
// 1：有効 0：無効
int	ft_isint(char *str)
{
	long	num;
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);

	// if (ft_strlen(str) > 11) //int型の最小値（-2147483648）が11文字なので、それを超えると確実に範囲外
	// 	return (0);

	//数字であるか調べる
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0) //現在の文字が数字じゃない(0)なら
			return (0); //0を返す
		i++;
	}
	num = ft_strtol(str);
	if (num < INT_MIN || INT_MAX < num)
		return (0);
	return (1);
}