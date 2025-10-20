/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:35:32 by turocha-          #+#    #+#             */
/*   Updated: 2025/09/03 18:37:00 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

size_t	gnl_strlen(char *s);
char	*gnl_strchr(char *s, int c);
char	*gnl_strjoin(char *file, char *buff);
char	*get_next_line(int fd);
char	*current_line(char *file);
char	*update_file(char *file);
char	*read_file(int fd, char *file);

#endif
