#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

int	get_next_line(int fd, char **line)
{
	static char	*saver;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes;
	int			finalsize;
	char		*tmp;

	bytes = 1;
	if (!saver)
	{
		saver = (char *)malloc(1);
		*saver = '\0';
	}
	// *line = 0;
	while (bytes)
	{
		finalsize = ft_strlen(saver);
		if (ft_strchr(saver, '\n'))
		{
			finalsize -= ft_strlen(ft_strchr(saver, '\n') + 1);
			*line = ft_substr(saver, 0, finalsize - 1);
			tmp = ft_substr(saver, finalsize, ft_strlen(saver) - finalsize);
			free(saver);
			saver = tmp;
			return (1);
		}
		bytes = read(fd, buffer, BUFFER_SIZE);
		saver = ft_strjoin(saver, buffer);
	}
	if (*line)
		free(*line);
	*line = saver;
	return (0);
}
