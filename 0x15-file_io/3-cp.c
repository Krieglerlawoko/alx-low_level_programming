#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fil);
/**
 * create_buffer - a function that prepares 1042 bytes 4 the buffer
 * @file: a pointer to the name of the file buffer stores char 4
 *
 * Return: returns a pointer to new alocated buffer
 */

char *create_buffer(char *file)
{
	char *bu;

	bu = malloc(sizeof(char) * 1024);

	if (bu == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);

		exit(99);
	}
	return (bu);
}
/**
 * close_file - a fucntion that closes the descriptors
 * @fil: this represents the file descriptor to close
 */

void close_file(int fil)
{
	int j;

	j = close(fil);

	if (j == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fil %d\n", fil);

		exit(100);
	}
}
/**
 * main - func copies content from another file
 * @argc: represents the no. of arguments supplied
 * @argv: this is an array of pointesr of the arguments
 *
 * Return: returns 0 if succesful
 *
 * Descrition: can't be read-exit 98, doesn't exit-97
 * can't be closed-exit 100,if can't write-exit 99
 */

int main(int argc, char *argv[])
{
	int cpFil;
	int putFil;
	int rid;
	int wrt;
	char *bu;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from_to\n");
		exit(97);
	}

	bu = create_buffer(argv[2]);
	cpFil = open(argv[1], O_RDONLY);
	rid = read(cpFil, bu, 1024);
	putFil = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);

	do {
		if (cpFil == -1 || rid == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);

			free(bu);

			exit(98);
		}

		wrt = write(putFil, bu, rid);
		if (cpFil == -1 || wrt == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't writ to %s\n", argv[2]);
			free(bu);

			exit(99);
		}
		rid = read(cpFil, bu, 1024);
		putFil = open(argv[2], O_WRONLY | O_APPEND);
	}

	while (rid > 0);
	free(bu);
	close_file(cpFil);
	close_file(putFil);
	return (0);
}
