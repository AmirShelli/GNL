#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
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
	static char	*saved;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes;

	bytes = 1;
	// if (!saved && fd >= 0)
	// {
	// 	saved = (char *)malloc(1);
	// 	*saved = '\0';
	// }
	while (bytes > 0)
	{
		if (ft_strchr(saved, '\n'))
			return (ft_getline(&saved, line));
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes > 0)
			saved = ft_strmcat(&saved, buffer, bytes);
	}
	*line = ft_substr(saved, 0, ft_strlen(saved));
	free(saved);
	if (!*line)
		return (-1);
	return (0);
}
