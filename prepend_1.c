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
	int i;

	i = 5;
	/**
	 * i is initially 5 because of "/bin/" has four characters
	 */

	i += _strlen(command);
	command_path = malloc(sizeof(char) * (i + 1));

	if (command_path == NULL)
		return (NULL);

	if (access(command, F_OK) == 0)
	{
		strcpy(command_path, command);
		command_path[_strlen(command)] = '\0';
		return (command_path);
	}
	strcpy(command_path, "/bin/");
	strcat(command_path, command);
	command_path[i] = '\0'; /**Null terminator**/
	return (command_path);
}
