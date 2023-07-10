#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int f);

/**
 * create_buffer - it allocates 1024 bytes for a buffer.
 * @file: the name of the file buffer is storing for characters
 * Return: A pointer to the newly-allocated buf
 */
char *create_buffer(char *file)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write %s\n", file);
		exit(99);
	}

	return (buf);
}

/**
 * close_file - It closes the file descriptors
 * @fd: The file descriptor ro be closed
 */
void close_file(int fd)
{
	int a;

	a = close(fd);

	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The num of arguments supplied to tthe program
 * @argv: An array of the pointers to the arguments
 * Return: 0 on success
 * Description: If the argument cont is incorrect - exit code 97
 * if file_from does neither exist nor be read - exit code 98
 * If file_to cannot be created nor written to - exit code 98
 * If file_to or file_from cannot be close - exit code 100
 */
int main(int argc, char *argv[])
{
	int from, to, p, q;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	p = read(from, buf, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || p == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buf);
			exit(98);
		}
		q = write(to, buf, p);
		if (to == -1 || q == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}

		p = read(from, buf, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (p > 0);

	free(buf);
	close_file(from);
	close_file(to);

	return (0);
}
