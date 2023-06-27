/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:02:48 by wvallee           #+#    #+#             */
/*   Updated: 2023/02/03 17:50:49 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_index(const char *s, int c)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			if (s[i] == (unsigned char)c)
				return (i);
			i++;
		}
		if (s[i] == (unsigned char)(c))
			return (i);
	}
	return (-1);
}

void	ft_cpy_fill(char *rest, int i)
{
	int	count;

	count = ft_strlcpy(rest, &rest[i + 1], BUFFER_SIZE + 2) + 1;
	while (rest[count] != '\0')
	{
		rest[count] = '\0';
		count++;
	}
}
