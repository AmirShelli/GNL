#include "./get_next_line/get_next_line_bonus.h"
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>  

int	get_next_line(int fd, char **line);

int	main(void)
{
	char	*line;
	int		fd;
	int		gnl;

	fd = open("/Users/bharghaz/Desktop/level_1/GNL/gnl.txt", O_RDONLY);
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		printf("this is line: |%s|\t%d\n\n", line, gnl);
		fflush(stdout);
		if (line)
			free(line);
	}
	printf("last line: |%s|\t%i\n\n", line, gnl);
	if (line)
		free(line);
	fflush(stdout);
	close(fd);
}
