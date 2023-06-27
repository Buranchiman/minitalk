/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:04:59 by wvallee           #+#    #+#             */
/*   Updated: 2023/02/20 11:12:45 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "ultralibft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int				ft_index(const char *s, int c);
void			ft_cpy_fill(char *rest, int i);
char			*ft_sub(char *s, unsigned int start, size_t len, char *rest);
char			*ft_strjoinf(char *s1, char *s2);
char			*dest_origin(char *dest, int fd);
char			*worker(char rest[FOPEN_MAX][BUFFER_SIZE + 1], int fd);
char			*get_next_line(int fd);

#endif
