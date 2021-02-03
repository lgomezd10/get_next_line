#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void probar(char *file)
{
	int fd;
	int res;
	char *str;
	
	fd = open(file, O_RDONLY);
	printf("fichero %s abierto con fd %d\n", file, fd);
	
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
	close(fd);
}

int main(void)
{
	int fd;
	int res;
	char *str;
	char *file;
	
	probar("4.txt");
		/*
		fd = open(file, O_RDONLY);
		printf("fichero %s abierto con fd %d\n", file, fd);
		
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
		close(fd);*/
/*
		file = ft_strcpy(file, "2.txt", 20);
		fd = open(file, O_RDONLY);
		printf("fichero %s abierto con fd %d\n", file, fd);

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
		close(fd);

		file = ft_strcpy(file, "3.txt", 20);
		fd = open(file, O_RDONLY);
		printf("fichero %s abierto con fd %d\n", file, fd);
		
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
		close(fd);

		file = ft_strcpy(file, "4.txt", 20);
		fd = open(file, O_RDONLY);
		printf("fichero %s abierto con fd %d\n", file, fd);
		
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
		close(fd);
*/
	//char *files[] = {"1.txt", "2.txt", "3.txt", "4.txt", "5.txt", "INVALID", 0};
	/*
	int i;
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
		//char *prueba = (char *)malloc(sizeof(char) * 7);
		//int sal = read(fd, prueba, 5);
		//printf("sal: %d, prueba: %s\n", sal, prueba);
		//free(prueba);
		i++;
		close(fd);
	}
	*/
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