/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:01:15 by wvallee           #+#    #+#             */
/*   Updated: 2022/11/22 12:01:14 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*worker;
	int		i;

	if (s != NULL)
	{
		worker = (char *)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
		if (worker == NULL)
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			worker[i] = f(i, s[i]);
			i++;
		}
		worker[i] = '\0';
	}
	else
		worker = NULL;
	return (worker);
}
