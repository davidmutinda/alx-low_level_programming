#include "main.h"
/**
 * read_textfile - reads a text file and prints it
 * @filename: constant string
 * @letters: number of letters it should read
 * Return: ssize_t
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, cl;
	char buf[1024];
	ssize_t max, min;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDWR);

	if (fd == -1)
		return (0);

	max = read(fd, buf, letters);
	if (max == -1)
		return (0);

	buf[max] = '\0';

	dprintf(STDOUT_FILENO, "%s", buf);

	min = write(fd, buf, max);
	if (min != max)
		return (0);

	cl = close(fd);
	if (cl == -1)
		return (0);
	return (max);

}
