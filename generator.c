#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * generator - generates an array of arguments to passed onto execve.
v===== * The string at index 0 is the file path location.
 *
 * @command: is the passed command requiring prepending.
 * @env_vars: is the list of environment variables.
 *
 * Return: returns an array of strings that are NULL terminated.
 */

char **generator(char *command, char *const env_vars)
{
	char *buffer, *token, *hold_first_token, **args;
	const char delim[] = " ";
	int arr_len, len, count;

	buffer = strdup(command);/**should be freed**/
	arr_len = total_array_length(buffer);
	args = malloc(sizeof(char *) * arr_len);/** needs to be freed **/
	len = 0;

	token = strtok(buffer, delim);
	hold_first_token = strdup(token);/**needs to be freed**/
	if (hold_first_token == NULL)
		return (NULL);

	char *first_var = prepend(hold_first_token);

	args[0] = malloc(sizeof(char) * _strlen(first_var)); /**needs to be freed**/
	strcpy(args[0], first_var);
	free(first_var);

	count = 1;
	while (token != NULL)
	{
		token = strtok(NULL, delim);
		if (token == NULL)
			break;

		len = _strlen(token);
		args[count] = malloc(sizeof(char) * len);/**to be freed**/
		strcpy(args[count], token);
		count++;
	}
	args[count] = NULL;
	free(buffer);
	printf("My token j1 is %s\n", args[1]);
	return (args);
}

/**
 * _strlen - gets the length of a string. including
 * the null terminator \0.
 *
 * @str: string whose length is to be found.
 * Return: length of String.
 */

int _strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;

	return (len + 1);
}

/**
 * total_array_length - gets the total array length needed
 * inclusive of NULL.
 *
 * @str: string passed.
 * Return: length of array needed.
 */

int total_array_length(char *str)
{
	char *buffer;
	int count_tokens;
	const char delim[] = " ";

	buffer = strdup(str);
	count_tokens = 0;
	char *token = strtok(buffer, delim);

	while (token != NULL)
	{
		count_tokens++;
		token = strtok(NULL, delim);
	}

	count_tokens += 1; /**including the count for the NULL termination**/
	free(buffer);/**had been created using strdup**/

	return (count_tokens);
}


/**
 * does_path_exist - checks if the path to the executable exists.
 *
 * @path: path passed to function.
 * Return: 1 if path exists else 0.
 */

int does_path_exist(char *path)
{
	if (access(path, F_OK) == 0)
		return (1);
	return (0);
}
