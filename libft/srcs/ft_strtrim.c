/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:28:12 by wvallee           #+#    #+#             */
/*   Updated: 2022/11/22 11:02:53 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*dest;

	if (s1 != NULL)
	{
		while (set != NULL && *s1 != '\0' && ft_strchr(set, *s1) != NULL)
			s1++;
		len = ft_strlen((char *)s1);
		while (set != NULL && len > 0 && ft_strchr(set, s1[len - 1]) != NULL)
			len--;
		dest = ft_strndup(s1, len);
	}
	else
		dest = NULL;
	return (dest);
}
