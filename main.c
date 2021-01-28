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

	
	res = get_next_line(fd, &str);
	printf("res: %d\n", res);
	printf("linea: %s\n", str);
	free(str);
	res = get_next_line(fd, &str);
	printf("res: %d\n", res);
	printf("linea: %s\n", str);
	free(str);
	res = get_next_line(fd, &str);
	printf("res: %d\n", res);
	printf("linea: %s\n", str);
	free(str);
	res = get_next_line(fd, &str);
	printf("res: %d\n", res);
	printf("linea: %s\n", str);
	free(str);
	close(fd);
}