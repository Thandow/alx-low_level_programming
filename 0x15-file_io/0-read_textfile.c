#include "main.h"
/**
 * read_textfile - it isa function that reads text file
 * and also prints it to the POSIX standard output
 * @filename: the file name
 * @letters: the number of letters
 * Return: the actual num of letters or 0 if fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t f;
	ssize_t r;
	ssize_t y;

	f = open(filename, O_RDONLY);
	if (f == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	y = read(f, buf, letters);
	r = write(STDOUT_FILENO, buf, y);

	free(buf);
	close(f);
	return (r);
}
