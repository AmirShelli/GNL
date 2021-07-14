#include "./get_next_line/get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  

int	get_next_line(int fd, char **line);

int	main(void)
{
	char	*line;
	int		gnl;
	int 	fd[4];

	fd[0] = open("/Users/bharghaz/Desktop/level_1/GNL/files/empty", O_RDWR);
	/* 1 */ gnl = get_next_line(1000, &line); 
	printf("test 1: |%s|\t%i\n\n", line, gnl);
	if (line)
		free(line);
	/* 2 */ gnl = get_next_line(fd[0], &line); 
	printf("test 2: |%s|\t%i\n\n", line, gnl);
	if (line)
		free(line);

	fd[1] = open("/Users/bharghaz/Desktop/level_1/GNL/files/42_with_nl", O_RDWR);
	/* 3 */ gnl = get_next_line(1001, &line);
	printf("test 3: |%s|\t%i\n\n", line, gnl);
	if (line)
		free(line);
	/* 4 */ gnl = get_next_line(fd[1], &line);
	printf("test 4: |%s|\t%i\n\n", line, gnl);
	if (line)
		free(line);

	fd[2] = open("/Users/bharghaz/Desktop/level_1/GNL/files/43_with_nl", O_RDWR);
	/* 5 */ gnl = get_next_line(1002, &line); 
	printf("test 5: |%s|\t%i\n\n", line, gnl);
	if (line)
		free(line);
	/* 6 */ gnl = get_next_line(fd[2], &line);
	printf("test 6: |%s|\t%i\n\n", line, gnl);
	if (line)
		free(line);

	/* 7 */ gnl = get_next_line(1003, &line); 
	printf("test 7: |%s|\t%i\n\n", line, gnl);
	if (line)
		free(line);
	/* 8 */ gnl = get_next_line(fd[0], &line);
	printf("test 8: |%s|\t%i\n\n", line, gnl);
	if (line)
		free(line);

	/* 9 */ gnl = get_next_line(1004, &line);
	printf("test 9: |%s|\t%i\n\n", line, gnl);
	if (line)
		free(line);
	/* 10 */ gnl = get_next_line(fd[1], &line);
	printf("test 10: |%s|\t%i\n\n", line, gnl);
	if (line)
		free(line);

	/* 11 */ gnl = get_next_line(1005, &line);
	printf("test 11: |%s|\t%i\n\n", line, gnl);
	if (line)
		free(line);
	/* 12 */ gnl = get_next_line(fd[2], &line);
	printf("test 12: |%s|\t%i\n\n", line, gnl);
	if (line)
		free(line);

	// fd[3] = open("files/nl", O_RDWR);
	// /* 13 */ gnl(1006, -1, NULL);
	// /* 14 */ gnl(fd[3], 1, "");
	// /* 15 */ gnl(1007, -1, NULL);
	// /* 16 */ gnl(fd[3], 0, "");
	// close(fd);
}
