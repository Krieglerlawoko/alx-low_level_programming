#include "main.h"

/**
 * create_file - this creates a file
 * @filename: this is a pointer to file name
 * @text_content: this is a pointer to a string to add
 *
 * Return: returns -1  on success else --1
 */

int create_file(const char *filename, char *text_content)
{
	int fil;
	int writ;
	int lenth = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lenth = 0; text_content[lenth];)
			lenth++;
	}
	fil = open(filename, O_CREATE | O_RDWR | O_TRUNC, 0600);
	writ = write(fil, text_content, lenth);

	if (fil == -1 || writ == -1)
		return (-1);
	close(fil);
	return (1);
}
