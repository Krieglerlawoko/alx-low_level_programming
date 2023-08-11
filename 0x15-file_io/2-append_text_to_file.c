#include "main.h"

/**
 * append_text_to_file - this adds text at the end of a file
 * @filename: this is a pointer to file to work on
 * @text_content: this is a string to be added
 *
 * Return: on fail returns NULL, --1 if no permission else 1
 */

int append_text_to_file(const *filename, char *text_content)
{
	int fil;
	int writ;
	int lnth = 0;

	if (text_content != NULL)
	{
		for (lnth = 0; text_content[lnth];)
			lnth++;
	}

	fil = open(filename, O_WRONGLY | O_APPEND);
	writ = write(fil, text_content, lnth);
	if (fil == -1 || writ == -1)
		return (-1);
	close(fil);
	return (1);
}
