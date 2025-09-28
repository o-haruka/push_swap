/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harukaomura <harukaomura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:46:50 by vscode            #+#    #+#             */
/*   Updated: 2025/05/22 21:25:16 by harukaomura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	len;

	len = ft_strlen(s1);
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, s1, len + 1);
	return (cpy);
}
