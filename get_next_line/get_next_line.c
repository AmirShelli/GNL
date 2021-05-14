#include "get_next_line.h"
#define BUFFER_SIZE 8

void	ft_savestr(char **into, char *from)
{
	unsigned int	finalsize;
	char			*aux_into;

	finalsize = ft_strlen(from);
	if (!*into)
		*into = ft_strdup(from);
	else
	{
		if (ft_strchr(from, '\n'))
			finalsize -= ft_strlen(ft_strchr(from, '\n'));
		aux_into = (char *)malloc(ft_strlen(*into) + finalsize + 1);
		// strcpy or smthing like that from into to aux_into
		aux_into = ft_strcpy(aux_into, from);
		free(*into);
		*into = ft_strncat(aux_into, from, finalsize);
		free(aux_into);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*saver;
	char		*buffer;
	int			bytes;


	while (bytes && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (-1);
		ft_savestr(&saver, buffer);
	}
	*line = ft_strdup((const char *)saver);
	if (ft_strchr(buffer, '\n'))
	{
		ft_savestr(&saver, ft_strchr(buffer, '\n') + 1); // + 1 if buffer[0] == \n
		return (1);
	}
	free(saver);
	return (0);
}
