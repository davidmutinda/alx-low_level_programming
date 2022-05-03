#include "main.h"
/**
 * read_textfile - reads a text file and prints it
 * @filename: constant string
 * @letters: number of letters it should read
 * Return: ssize_t
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buf;
	ssize_t max, min;

	if (filename == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters);
	fd = open(filename, O_RDWR);

	if (fd == -1)
	{
		free(buf);
		return (0);
	}

	if (letters > 0)
	{
		max = read(fd, buf, letters);
		if (max == -1)
			return (0);
		buf[max] = '\0';

		min = write(1, buf, max);
		if (min != max)
			return (0);
	}
	else
		max = 0;

	free(buf);
	close(fd);
	return (max);

}
