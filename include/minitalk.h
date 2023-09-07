/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:47:56 by wvallee           #+#    #+#             */
/*   Updated: 2023/06/15 13:48:44 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ultralibft.h"
# include <signal.h>

typedef struct s_charlist
{
	char                c;
	struct s_charlist	*next;
}					t_charlist;

int	ft_charlstsize(t_charlist *lst);
void	clean_charlist(t_charlist *a);
void	manage_charlist(t_charlist **msg, char	c);

#endif