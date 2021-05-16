#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

// int	get_next_line(int fd, char **line)
// {
// 	static char	*saved;
// 	char		buffer[BUFFER_SIZE + 1];
// 	int			bytes;

// 	if (fd < 0 || BUFFER_SIZE < 1 || !line || read(fd, buffer, 0) < 0)
// 		return (-1);
// 	bytes = 1;
// 	while (bytes)
// 	{
// 		if (ft_strchr(saved, '\n'))
// 			return (ft_getline(&saved, line));
// 		bytes = read(fd, buffer, BUFFER_SIZE);
// 		saved = ft_strmcat(&saved, buffer, bytes);
// 	}
// 	*line = ft_substr(saved, 0, ft_strlen(saved));
// 	free(saved);
// 	if (!*line)
// 		return (-1);
// 	return (0);
// }

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
		if (bytes)
			saver = ft_strnjoin(saver, buffer, bytes);
	}
	*line = ft_substr(saver, 0, ft_strlen(saver));
	return (0);
}
