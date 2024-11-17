#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*return_line(char **buffer);
char	*ft_next(char *buffer);
char	*read_buffer(int fd, char *buffer);
char	*read_line(char *buffer);
char	*free_buffer(char *buffer);
size_t	ft_strlen(char *s);
char	*ft_calloc(size_t n, size_t size);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);

#endif
