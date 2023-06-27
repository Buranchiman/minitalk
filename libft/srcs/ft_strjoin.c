/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:49:55 by wvallee           #+#    #+#             */
/*   Updated: 2022/11/22 12:00:29 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		size;
	char	*fusion;
	int		count;

	fusion = NULL;
	if (s1 != NULL || s2 != NULL)
	{
		if (s1 == NULL)
			fusion = strdup(s2);
		else if (s2 == NULL)
			fusion = strdup(s1);
		else
		{
			size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
			fusion = (char *)ft_calloc(size + 1, sizeof(char));
			count = ft_strlen((char *)s2) + ft_strlen((char *)s1) + 1;
			ft_strlcpy(fusion, (char *)s1, ft_strlen((char *)s1) + 1);
			ft_strlcat(fusion, (char *)s2, count);
		}
	}
	return (fusion);
}
