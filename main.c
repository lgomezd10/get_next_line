#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;
	int res;
	char *str;
	
	//t_listc *list;

<<<<<<< HEAD
	//char *file = "2.txt";
	char *file = "INVALID_FD";
	fd = open(file, O_RDONLY);
	printf("fichero %s abierto\n", file);

	res = 1;
	while (res == 1)
	{
		res = get_next_line(fd, &str);
		printf("res: %d, linea: %s\n", res, str);
		free(str);
	}
=======
	
	fd = open("archivo", O_RDONLY);
	printf("fichero abierto\n");

	res = 1;

	while (res == 1)
	{
		res = get_next_line(fd, &str);
		printf("leido: %s resp: %d\n", str, res);
		free (str);
	}
	printf("Ha terminado la lectura con el valor: %d\n", res);
	close(fd);
>>>>>>> b64a22103af9962f132f57f530ddf62d55bc8071
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
	close(fd);
	*/
}