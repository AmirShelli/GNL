#include "./get_next_line/get_next_line.h"
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>  

int	get_next_line(int fd, char **line);

int	main(void)
{
	char	*line;
	 int fd = open("./testfile.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("this is line: |%s|\n\n", line);
		fflush(stdout);
		if (line)
			free(line);
	}
	printf("this is line: |%s|\n\n", line);
		fflush(stdout);
		if (line)
		free(line);
	close(fd);
}
