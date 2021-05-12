# define BUFFER_SIZE 8

int	get_next_line(int fd, char **line)
{
	static char	*saver;
	char		*buffer;
	int			bytes;

	line = (char **)malloc(sizeof(char *));
	while (bytes && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (-1);
		saver = ft_savestr(saver, buffer);
	}
	*line = (char *)malloc(ft_strlen(saver) + 1);
	*line = saver;
	saver = ft_savestr(saver, ft_strchr(buffer, '\n') + 1); // + 1 if buffer[0] == \n 
	// better always save and intialize with \0 (don't forget malloc for 1 byte!)
	if (ft_strchr(buffer, '\n'))
		return (1);
	return(0);
}