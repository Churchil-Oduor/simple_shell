#include <unistd.h>
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1024


int _strcmp(char *str_1, char *str_2);
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

		command[response - 1] = '\0';/** null terminal**/

		if (response == -1)
		{
			free(command);
			break;
		}

		if (_strcmp(command, "exit") == 1)
			exit(EXIT_SUCCESS);

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
 * _strcmp - compares two strings.
 * @str_1: string 1.
 * @str_2: string 2.
 * Return: 1 if equal 0 if not equal.
 */

int _strcmp(char *str_1, char *str_2)
{
	int len_1, len_2, index;

	len_1 = _strlen(str_1);
	len_2 = _strlen(str_2);

	if (len_1 != len_2)
		return (0);

	index = 0;
	while (index != len_1)
	{
		if (str_1[index] != str_2[index])
			return (0);
		index++;
	}
	return (1);
}	
