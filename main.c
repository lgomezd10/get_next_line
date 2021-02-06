#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;
	int res;
	char *str;
/*
	fd = open("3.txt", O_RDONLY);
		printf("fichero abierto con fd %d\n", fd);

char otro[] = "que pasa por tu casa";
char *prueba = (char *)malloc(sizeof(char) * 7);
		int sal = read(fd, otro, 5);
		printf("sal: %d, prueba: %s %d\n", sal, otro, otro[0]);
		free(prueba);
*/
	
	int i;
	char *files[] = {"1.txt", "2.txt", "3.txt", "4.txt", "5.txt", "6.txt", "INVALID", 0};
	//char *files[] = {"big_line_no_nl", 0};
	
	i = 0;
	while (files[i] != 0)
	{
		fd = open(files[i], O_RDONLY);
		printf("fichero %s abierto con fd %d\n", files[i], fd);

		res = 1;
		while (res == 1)
		{
			res = get_next_line(fd, &str);
			printf("res: %d, linea: %s\n", res, str);
			free(str);
		}
		res = get_next_line(fd, &str);
		printf("res: %d, linea: %s\n", res, str);
		free(str);
		i++;
		close(fd);
	}
	
	/*
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
	*/
	
}