#include "main.h"
/**
 * create_file - creates a file
 * @filename: A pointer to the file name to create
 * @text_content: A pointer to string so to write to the file
 * Return: If the function fails --1
 * Otherwise - 1
 */
int create_file(const char *filename, char *text_content)
{
	int f, r, l = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (l = 0; text_content[l];)
			l++;
	}

	f = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	r = write(f, text_content, l);

	if (f == -1 || r == -1)
		return (-1);

	close(f);

	return (1);
}
