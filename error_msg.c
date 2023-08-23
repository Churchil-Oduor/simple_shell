#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * error_msg - prints the relevant error message if the
 * file path is not found.
 *
 * @mode: 1 represents the interactive mode 0 represents the
 * non interactive mode.
 * @file_name: name to the executable file.
 * @path: path to the executable.
 *
 * Return: 1 if error exists in path else 0.
 *
 */

int error_msg(int mode, char *file_name, char *path)
{
	int file_length, path_length;

	file_length = _strlen(file_name);
	path_length = _strlen(path);
	if (mode == 1)
	{
		write(STDOUT_FILENO, file_name, file_length);
		write(STDOUT_FILENO, ": No such file or directory", 27);
		return (1);
	}
	else if (mode == 0)
	{
		write(STDOUT_FILENO, file_name, file_length);
		write(STDOUT_FILENO, ": 1: ", 5);
		write(STDOUT_FILENO, path, path_length);
		write(STDOUT_FILENO, ": not found", 11);
		write(STDOUT_FILENO, "\n", 1);
		return (1);
	}
	else
		return (1);
}

