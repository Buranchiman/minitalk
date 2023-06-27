/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:03:11 by wvallee           #+#    #+#             */
/*   Updated: 2022/11/22 11:13:54 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s)
{
	int		size;
	char	*tab;

	size = ft_strlen((char *)s);
	tab = (char *)malloc((size + 1) * sizeof(char));
	if (tab != NULL)
		ft_strlcpy(tab, s, size + 1);
	return (tab);
}
