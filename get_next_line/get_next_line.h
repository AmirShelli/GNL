#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *src, int c);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
char	*ft_strdup(char *src);
char	*ft_strcpy(char *dest, char *src);

#	endif