#include <unistd.h>
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1024

/**
 * interactive_mode - the function managing interactive mode.
 *
 * @file_name: the name of the file used in starting the shell
 * e.g hsh ..etc.
 * @env_vars: environment variables picked from main function
 * present in file shell.c
 */

void interactive_mode(char *file_name, char *const env_vars[])
{
	while (1)
	{
		size_t len;
		ssize_t response;
		char **args, *command, *prompt_symbol;

		len = 0;
		command = NULL;
		prompt_symbol = "($) ";
		write(STDOUT_FILENO, prompt_symbol, 4);
		response = getline(&command, &len, stdin); /**command should be freed**/

		if (response == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			free(command);
			break;
		}
		command[len - 1] = '\0';/** null terminate**/
		args = generator(command);
		/**
		 * do an error check
		 */
		if (does_path_exist(args[0]) == 0)
			error_msg(1, file_name, command);
		else
			execute(args, env_vars);
		free(command);

	}
}

/**
 * signal_handler - handles CTRL+C and CTRL+D interrupts.
 * @signum: signal number to be handled.
 * Return: signal number signum.
 */

int signal_handler(int signum __attribute__((unused)))
{
	return (0);
}
