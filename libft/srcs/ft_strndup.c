/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:20:26 by wvallee           #+#    #+#             */
/*   Updated: 2022/11/22 11:07:29 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*tab;
	size_t	i;

	i = 0;
	tab = (char *)malloc(n + 1 * sizeof(char));
	if (tab != NULL)
	{
		while (i < n && s[i] != '\0')
		{
			tab[i] = s[i];
			i++;
		}
		tab[i] = '\0';
	}
	return (tab);
}
