
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

size_t	ft_strlen_gnl(char *s);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *not_read, char *buff);
char	*get_next_line(int fd);
char	*cur_line(char *not_read);
char	*new_not_read(char *not_read);
char	*read_not_read(int fd, char *not_read);

#endif
