#include "./get_next_line/get_next_line_bonus.h"
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>  

int	get_next_line(int fd, char **line);

int	main(void)
{
	char	*line;
	int		fd, fd_1;
	int		gnl;

	fd = open("/Users/bharghaz/Desktop/level_1/GNL/gnl.txt", O_RDONLY);
	fd_1 = open("/Users/bharghaz/Desktop/level_1/GNL/gnl_1.txt", O_RDONLY);
	while ((gnl = get_next_line(fd_1, &line)) > 0)
	{
		printf("this is line: |%s|\t%d\n\n", line, gnl);
		fflush(stdout);
		if (line)
			free(line);
	}
	printf("last line: |%s|\t%i\n\n", line, gnl);
	if (line)
		free(line);
	gnl = get_next_line(fd_1, &line);
	printf("last line: |%s|\t%i\n\n", line, gnl);
	if (line)
		free(line);
	fflush(stdout);

	// gnl = get_next_line(fd, &line);
	// printf("this is line: |%s|\t%d\n\n", line, gnl);
	// free(line);
	// gnl = get_next_line(fd_1, &line);
	// printf("this is line: |%s|\t%d\n\n", line, gnl);
	// free(line);
	// gnl = get_next_line(fd, &line);
	// printf("this is line: |%s|\t%d\n\n", line, gnl);
	// free(line);
	// gnl = get_next_line(fd_1, &line);
	// printf("this is line: |%s|\t%d\n\n", line, gnl);
	// free(line);
	// gnl = get_next_line(fd, &line);
	// printf("this is line: |%s|\t%d\n\n", line, gnl);
	// free(line);
	close(fd);
}
