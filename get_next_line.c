# define BUFFER_SIZE 8

int	get_next_line(int fd, char **line)
{
	static char	*saver;
	char		*buffer;
	int			bytes;

	line = (char **)malloc(sizeof(char *));
	while (bytes)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (bytes);
		saver = ft_savestr(saver, buffer);
		if (ft_strchr(buffer, "\n"))
		{
			*line = (char *)malloc(ft_strlen(saver) + 1);
			*line = saver;
			saver = ft_savestr(saver, buffer + 1); // + 1 if buffer[0] == \n 
			return (1);
		}								
	}
}