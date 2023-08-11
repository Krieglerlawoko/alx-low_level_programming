#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - this reads file text & prints to STDOUT
 * @filename: this is the file to be read
 * @letters: this represents the no. of letters to read
 *
 * Return: returns numbeer of byte read else NULL
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *bu;
	ssize_t fil;
	ssize_t wrt;
	ssize_t rid;

	fil = open(filename, O_RDONLY);

	if (fil == -1)
		return (0);
	bu = malloc(sizeof(char) * letters);
	rid = read(fil, bu, letters);
	wrt = write(STDOUT_FILENO, bu, rid);

	free(bu);
	close(fil);

	return (wrt);
}

