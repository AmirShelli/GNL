#include "./get_next_line/get_next_line.h"
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>  

int	get_next_line(int fd, char **line);

int	main(void)
{
	char	*line;
	 int fd = open("/Users/bharghaz/Desktop/level_1/GNL/testfile.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("this is line: |%s|\n\n", line);
		fflush(stdout);
		// if (line)
		// 	free(line);
	}
	write(1,"here\n",5);
	printf("this is line: |%s|\n\n", line);
		fflush(stdout);
		// if (line)
	// 	free(line);
	close(fd);
}
