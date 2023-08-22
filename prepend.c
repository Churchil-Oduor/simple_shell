#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * prepend - this function prepends raw passed commands
 * with /bin/
 *
 * @command: passed command that requires prepending.
 * Return: /bin/ls prepended string.
 */

char *prepend(char *command)
{
	char *command_path;
	int i, len;

	/**
	 * check if the file is in the current directory
	 */
	if (access(command, F_OK) == 0)
		return (command);

	i = 5;
	/**
	 * i is initially 5 because o "/bin/" has four characters
	 */

	i += _strlen(command);

	command_path = malloc(sizeof(char) * (i + 1));
	/**
	 * added 1 to accomodate the null terminator and avoiding memory leak
	 */

	if (command_path == NULL)
		return (NULL);

	strcpy(command_path, "/bin/");
	strcat(command_path, command);
	len = _strlen(command_path);
	command_path[len] = '\0'; /**Null terminator**/

	return (command_path);
}
