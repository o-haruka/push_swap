/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:38:04 by vscode            #+#    #+#             */
/*   Updated: 2025/05/09 19:38:07 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	value;

	p = (unsigned char *)b;
	value = (unsigned char)c;
	while (0 < len)
	{
		*p = value;
		p++;
		len--;
	}
	return (b);
}
