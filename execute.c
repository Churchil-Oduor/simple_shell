#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include "main.h"

/**
 * execute - this function checks whether the
 * path to the executable exists. If it does exist, it creates
 * a child via fork else an error message is printed.
 *
 * @args: is an array of strings that is null terminated.
 * @env_vars: list of environment variables carried all the way from
 * main() present in our shell.c file
 *
 * Return: returns 1 if it executed successfully else -1;
 */

int execute(char **args, char *const env_vars[])
{
	/**code here**/
	int child, status;

	if (does_path_exist(args[0]) == 0)
		return (-1);

	child = fork();
	if (child < 0)
		perror("could not form child");
	else if (child == 0)
		execve(args[0], args, env_vars);
	else
		wait(&status);

	return (1);
}
