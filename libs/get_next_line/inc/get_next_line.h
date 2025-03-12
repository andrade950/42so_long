/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:39:16 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/11 18:31:54 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_read_to_left_str(int fd, char *left_str);
char	*gnl_ft_strchr(char *s, int c);
char	*gnl_ft_strjoin(char *left_str, char *buff);
size_t	gnlstrlen(char *s);
char	*ft_get_line(char *left_str);
char	*ft_new_left_str(char *left_str);

#endif
