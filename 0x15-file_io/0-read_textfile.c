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
	ssize_t writFil;
	ssize_t readFil;
	ssize_t file;
	char *b;

	file = open(filename, 0_RDONLY);
	if (file == -1)
		return (0);
	b = malloc(sizeof(char) * letters);
	ReadFil = read(file, b, letters);
	writFil = write(STDOUT_FILENO, b, readFil);

	free(b);
	close(file);
	return (writFil);
}
