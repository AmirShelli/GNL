# define BUFFER_SIZE 8

int	get_next_line(int fd, char **line)
{
	static char	*saver;
	char		*buffer;
	int			bytes;

	line = (char **)malloc(sizeof(char*));
	while (bytes)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (bytes);
		saver = ft_savestr(buffer, saver);	
		if (ft_strchr(bytes, "\n"))			
		{
			*line = (char *)malloc(ft_strlen(saver) + 1);
			*line = saver;					
		}								
											
											
	}
}