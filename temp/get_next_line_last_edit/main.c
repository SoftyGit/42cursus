#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.c"
#include "get_next_line_utils_bonus.c"
#include "get_next_line_bonus.h"
#define LOCK 0

int main()
{
	char *ret;
	int fd0, fd1, fd2, fd3;

	fd0 = open("c.txt", O_RDONLY);
	fd1 = open("a.txt", O_RDONLY);
	fd2 = open("b.txt", O_RDONLY);
	fd3 = open("d.txt", O_RDONLY);
	
	printf("%s",ret = get_next_line(fd3));
	free(ret);
	printf("%s",ret = get_next_line(fd3));
	free(ret);
	printf("%s",ret = get_next_line(fd3));
	free(ret);
	printf("%s",ret = get_next_line(fd3));
	free(ret);
	printf("%s",ret = get_next_line(fd3));
	free(ret);
	return 0;
	printf("%s",ret = get_next_line(fd0));
	printf("%s\n",get_next_line(fd0));
	if (LOCK)
		system("leaks a.out");
	printf("%s",get_next_line(fd1));
	printf("%s",get_next_line(fd1));
	printf("%s",get_next_line(fd1));
	printf("%s",get_next_line(fd1));
	printf("%s\n",get_next_line(fd1));
	if (LOCK)
		system("leaks a.out");
	printf("%s",get_next_line(fd2));
	printf("%s",get_next_line(fd2));
	printf("%s\n",get_next_line(fd2));
	if (LOCK)
		system("leaks a.out");
}