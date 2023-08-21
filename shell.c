#include <unistd.h>
#include "main.h"


/**
 * main - entry point to the program.
 * Using isatty() function, determines the mode of operation
 * either interactive or non_interactive_mode.
 *
 * @ac: is the total number of command line inputs.
 * @args: arrays of strings passed in the command line.
 * @env_vars: list of environment variables.
 *
 * Return: always 1.
 */

int main(int ac, char **args __attribute__((unused)),
		char *const env_vars[] __attribute__((unused)))
{

	if (isatty(STDIN_FILENO))
		interactive_mode(args[0], env_vars);
	else
		non_interactive_mode(args[0], env_vars);

	return (0);
}
