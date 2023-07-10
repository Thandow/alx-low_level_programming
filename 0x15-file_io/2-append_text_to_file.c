#include "main.h"
/**
 * append_text_to_file - it appends the text at the end of a file.
 * @filename: A pointer to the name of file
 * @text_content: String to add at the file end
 * Return: If the function fails or filename is NULL -- 1.
 * if the file does not exist the user lacks write permissions -- 1.
 * Otherwise - 1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int p, r, l = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (l = 0; text_content[l];)
			l++;
	}

	p = open(filename, O_WRONLY | O_APPEND);
	r = write(p, text_content, l);

	if (p == -1 || r == -1)
		return (-1);

	close(p);

	return (1);
}
