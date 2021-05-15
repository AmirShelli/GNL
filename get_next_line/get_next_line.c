#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

void	ft_checkmalloc(char **saver, char **line)
{
	if (!*saver)
	{
		*saver = (char *)malloc(1);
		**saver = '\0';
	}
	if (*line)
		free(*line);	
}

int	get_next_line(int fd, char **line)
{
	static char	*saver;
	char		*tmp;
	char		buffer[BUFFER_SIZE + 1];
	int		bytes;
	
	bytes = 1;
	ft_checkmalloc(&saver, line); // unprotected, add more checkers for -1
	while (bytes)
	{
		if (ft_strchr(saver, '\n'))
		{
			*line = ft_substr(saver, 0, ft_strlen(saver) - ft_strlen(ft_strchr(saver, '\n')); // unprotected
			tmp = ft_substr(saver, ft_strlen(saver) - ft_strlen(ft_strchr(saver, '\n'), \
				ft_strlen(ft_strchr(saver, '\n') + 1); // unprotected
			free(saver);
			saver = tmp;
			return (1);
		}
		bytes = read(fd, buffer, BUFFER_SIZE);
		saver = ft_strnjoin(saver, buffer, bytes); // unprotected
	}
	*line = saver;
	return (0);
}
