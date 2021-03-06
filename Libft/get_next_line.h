/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:15:56 by molabhai          #+#    #+#             */
/*   Updated: 2020/12/03 16:38:38 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define TRUE 			1
# define FALSE 			0

# define BUFFER_SIZE  10

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "libft.h"

int						get_next_line(int fd, char **line);
void					*ft_calloc(size_t count, size_t size);
int						search(char *str);
char					*extend(char *str, char *s);
void					return_free_last(char **tmp, char **ptr, char **o_tmp,
							char **line);
char					*return_line(char **tmp, char **line, char **ptr,
							char *str);
char					*return_rest(char **ptr, char **line, char **o_tmp,
							char **tmp);
int						word_len(char *str, int i);

#endif
