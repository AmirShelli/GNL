#include "./get_next_line/get_next_line.h"
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>  

int	get_next_line(int fd, char **line);

int	main(void)
{
	char	*line;
	int		fd;
	int		gnl;

	fd = open("./testfile.txt", O_RDONLY);
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		printf("this is line: |%s|\t%d\n\n", line, gnl);
		fflush(stdout);
		if (line)
			free(line);
	}
	printf("this is line: |%s|\t%i\n\n", line, gnl);
	if (line)
		free(line);
	fflush(stdout);
	close(fd);
}
