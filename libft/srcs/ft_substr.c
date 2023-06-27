/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:56:32 by wvallee           #+#    #+#             */
/*   Updated: 2022/11/22 11:08:39 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	ft_getlen(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = start;
	if (ft_strlen((char *)s) <= start)
		return (0);
	while (s[i] != '\0')
		i++;
	if (i - start < len)
		return (i - start);
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	truth;
	size_t	count;
	char	*dest;

	if (s != NULL)
	{
		count = 0;
		truth = ft_getlen(s, start, len);
		dest = (char *)malloc(truth + 1 * sizeof(char));
		if (dest == NULL)
			return (NULL);
		while (count < truth)
		{
			dest[count] = s[start];
			count++;
			start++;
		}
		dest[count] = '\0';
	}
	else
		dest = NULL;
	return (dest);
}
