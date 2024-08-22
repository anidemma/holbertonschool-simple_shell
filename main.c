#include "main.h"
/**
 * split - function for parsing command
 * @command: command to be parsed
 * @args: arguments to command
 * 
 * Return - void
*/
void split(char *command, char **args)
{
	int i = 0;
	char *token = strtok(command, " \t");

	args[i] = NULL;
	while (token != NULL && i < MAX_LEN - 1)
	{
		args[i] = token;
		token = strtok(NULL, " \t");
		i++;
	}
	args[i] = NULL;
}

/**
 * split_newline - seperates by newline
 * @commands: commands
 * @commands_arr: array for all commands
 *
 * Return - void
*/
void split_newline(char *commands, char **commands_arr)
{
	char *command;
	int i = 0;

	command = strtok(commands, "\n");
	for (; command; i++)
	{
		commands_arr[i] = command;
		command = strtok(NULL, "\n");
	}
	commands_arr[i] = NULL;
}

/**
 * execute - function to  execute the command
 * @args: arguments to path
 * @path: path
 * 
 * Return - void
 */
void execute (char **args, char *path)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
		{
			free(path);
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (wait(NULL) == -1)
		{
			free(path);
			perror("wait failed");
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * main - main function
 *
 * Return: int
 */
int main(void)
{
	char commands[MAX_LEN];
	char *commands_arr[MAX_LEN];
	ssize_t nread;

	while (1)
	{
		nread = read(STDIN_FILENO, commands, MAX_LEN);
		if (nread == -1)
		{
			perror("Error reading command");
			exit(EXIT_FAILURE);
		}
		else if (nread == 0)
		{
			break;
		}
		commands[nread] = '\0';

		split_newline(commands, commands_arr);
		handle_commands_arr(commands_arr);
	}
	return (0);
}
