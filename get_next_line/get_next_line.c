#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 34
#endif

void	ft_savestr(char **into, char *from)
{
	unsigned int	finalsize;
	char			*tmp_into;

	finalsize = ft_strlen(from);
	if (!*into)
	{
		*into = (char *)malloc(1);
		**into = '\0';
	}
	if (ft_strchr(from, '\n'))
		finalsize -= ft_strlen(ft_strchr(from, '\n'));
	tmp_into = (char *)malloc(ft_strlen(*into) + finalsize + 1);
	tmp_into = ft_strcpy(tmp_into, *into);
	free(*into);
	*into = ft_strncat(tmp_into, from, finalsize);
}

int	get_next_line(int fd, char **line)
{
	static char	*saver;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes;

	bytes = 1;
	while (bytes && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (-1);
		buffer[bytes] = '\0';
		ft_savestr(&saver, buffer);
		printf("saver: %s\n", saver);
	}
	*line = ft_strdup(saver);
	free(saver);
	if (ft_strchr(buffer, '\n'))
	{
		ft_savestr(&saver, ft_strchr(buffer, '\n') + 1);
		return (1);
	}
	return (0);
}
