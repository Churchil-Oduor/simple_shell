#include <unistd.h>
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 512

/**
 * non_interactive_mode - the function managing interactive mode.
 *
 * @file_name: the name of the file used in starting the shell
 * e.g hsh ..etc.
 * @env_vars: environment variables picked from main function
 * present in file shell.c
 */

void non_interactive_mode(char *file_name, char *const env_vars[])
{
	char *command, **args;
	int read_bytes;

	command = malloc(sizeof(char) * BUFFER_SIZE);

	if (command == NULL)
		exit(EXIT_FAILURE);


	read_bytes = read(STDIN_FILENO, command, BUFFER_SIZE);
	if (read_bytes < 0)
	{
		perror("Error reading command from terminal");
		exit(EXIT_FAILURE);
	}
	command[read_bytes - 1] = '\0';
	args = generator(command);

	/**
	 * do an error check
	 */
	if (does_path_exist(args[0]) == 0)
		error_msg(0, file_name, command);
	else
		execute(args, env_vars);
	free(command);
}
