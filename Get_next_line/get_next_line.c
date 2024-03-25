/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpalacio <kpalacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:18:33 by kpalacio          #+#    #+#             */
/*   Updated: 2024/03/25 16:21:53 by kpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	static ssize_t bytes;
	static char *buffer;
	size_t count;

	buffer = (char *)malloc(sizeof(char) * 1024);
	if (!buffer)
		return (NULL);
	count = 20;
	while(read(fd, void *buffer, count) != '\n')
		bytes = read(int fd, void *buffer, size_t count);
	return (buffer);
}

int main()
{
	char *line;
	int fd;
	fd = open("~/Desktop/hola.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error al abrir el archivo");
		return (0);
	}
	while (get_next_line(fd))
		printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
