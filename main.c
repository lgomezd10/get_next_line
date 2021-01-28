#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;
	int res;
	char *str;
	//t_listc *list;

	fd = open("archivo", O_RDONLY);
	printf("fichero abierto\n");

	
	res = get_next_line(fd, &str);
	printf("res 1: %d\n", res);
	printf("main 1: %s\n", str);
	free(str);
	
	res = get_next_line(fd, &str);
	printf("res 2: %d\n", res);
	printf("main 2: %s\n", str);
	free(str);
	str = 0;
	res = get_next_line(fd, &str);
	printf("res 3: %d\n", res);
	printf("main 3: %s\n", str);
	free(str);
	str = 0;
	res = get_next_line(fd, &str);
	printf("res 4: %d\n", res);
	printf("main 4: %s\n", str);
	free(str);
	close(fd);
}