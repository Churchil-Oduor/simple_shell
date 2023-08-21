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

	/**
	 * check if the file is in the current directory
	 */
	if (access(command, F_OK) == 0)
		return (command);

	i = 5;
	/**
	 * i is initially 5 because o "/bin/" has four characters
	 */
	while (command[i] != '\0')
		i++;

	command_path = malloc(sizeof(char) * i);
	if (command_path == NULL)
		return (NULL);

	strcpy(command_path, "/bin/");
	strcat(command_path, command);

	return (command_path);
}
