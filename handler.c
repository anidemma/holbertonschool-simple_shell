#include "main.h"

/**
 * handle_path - function for handling path
 * @args: arguments
 * @path: path
 * @path_env: environment path
 * @flag: checks that if found
 * 
 * Return - void
*/
void handle_path(char **args, char **path, char **path_env, int *found)
{
	char *token = NULL;

	if (*path_environ == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		free(*path_environ);
		free(*path);
		exit(123);
	}
	token = strtok(*path_environ, ":");
	while (token)
	{
		strcpy(*path, token);
		strcat(*path, "/");
		strcat(*path, args[0]);
		if (access(*path, X_OK) == -1)
		{
			*flag = 1;
			break;
		}
		token = strtok(NULL, ":");
	}
	free(*path_environ);
}


/**
 * handle_command - command handler
 * @command: command
 *
 * Return - void
*/
void handle_command(char *command)
{
	char *args[MAX_LEN];
	char *path = NULL;
	char *path_env = NULL;
	int flag = 0;

	set_env(&path, &path_env);
	split(command, args);

	if (args[0] == NULL)
	{
		free(path_env);
		free(path);
		return;
	}
	
	if (strchr(args[0], '/') == NULL)
	{
		if (access(args[0], X_OK) == -1)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			free(path_env);
			free(path);
			exit(123);
		}
		free(path_env);
		free(path);
		path = strdup(args[0]);
		flag = 1;
	}
	else
	{
		handle_path(args, &path, &path_env, &flag);
	}
	if (flag == 0)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		free(path);
		exit(123);
	}
	execute(args, path);
	free(path);
}

/**
 * handle_commands_arr - function for handling array of commands
 * @commands_arr: 2d array
 *
 * Return - void
 */
void handle_commands_arr(char **commands_arr)
{
	char *command;
	int i = 0;

	if (strcmp(commands_arr[i], "env") == 0)
	{
		print_environ();
	}
	else if (strcmp(comands_arr[i], "exit") == 0)
	{
		exit(0);
	}
	else
	{
		for (; commands_arr[i]; i++)
		{
			command = commands_arr[i];
			if (strcmp(command, "exit") == 0 && i > 0)
			{
				exit(1);
			}
			handle_command(command);
		}
	}
}

