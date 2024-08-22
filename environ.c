#include "main.h"

/**
 * print_environ - function for printing environment
 *
 * Return - void
*/
void print_environ(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		printf("%s", environ[i]);
	}
}

/**
 * set_env - function for setting up environment
 * @path_env: environment path
 * @path: path
 *
 * Return - void
*/
void set_env(char **path_env, char **path)
{
	int i = 0;

	*path = malloc(MAX_LEN);
	if (*path == NULL)
	{
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}
	memset(*path, 0, MAX_LEN);

	while (environ[i])
	{
		if (strncmp(environ[i], PATH, 5) == 0)
		{
			*path_env = strdup(environ[i] + 5);
			break;
		}
		i++;
	}
}
