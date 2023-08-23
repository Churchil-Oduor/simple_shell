#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * generator - generates an array of arguments to passed onto execve.
 * The string at index 0 is the file path location.
 *
 * @command: is the passed command requiring prepending.
 *
 * Return: returns an array of strings that are NULL terminated.
 */

char **generator(char *command)
{
	char *buffer, *token, *hold_first_token, **args, *first_var;
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

	first_var = prepend(hold_first_token);

	args[0] = malloc(sizeof(char) * (_strlen(first_var) + 1));
	strcpy(args[0], first_var);
	free(first_var);/**freeing because in the prepend fx, strdup was used**/

	count = 1;
	while (token != NULL)
	{
		token = strtok(NULL, delim);
		if (token != NULL)
		{
			len = _strlen(token) + 1;/**added one to account for the null terminator**/
			args[count] = malloc(sizeof(char) * len);/**to be freed**/
			strcpy(args[count], token);
			count++;
		}
	}
	args[count] = NULL;
	free(buffer);
	free(hold_first_token);
	return (args);
}

/**
 * _strlen - gets the length of a string. excluding
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

	return (len);
}

/**
 * total_array_length - gets the total array length needed
 * inclusive of NULL.
 *
 * @str: string passed.
 * Return: length of array needed else -1 if error occured
 */

int total_array_length(char *str)
{
	int count_tokens;
	char *token, *buffer;
	const char delim[] = " ";

	buffer = strdup(str);

	if (buffer == NULL)
		return (-1);
	count_tokens = 0;
	token = strtok(buffer, delim);

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

/**
 * free_args - this function frees args preventing memory leaks.
 * should after you are done using args contents.
 * @args: array of strings
 */

void free_args(char **args)
{
	int index;

	index = 0;
	while (args[index] != NULL)
	{
		free(args[index]);
		index++;
	}

	free(args);
}
