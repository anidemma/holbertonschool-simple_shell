#include "main.h"

/**
 * handle_commands_array - func for handling array of commands
 * @commands_array: array of commands
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
				handle_command(command);
			}
		}
	}
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
}
















/**
 * main - main function
 *
 * Return: int
 */
int main(void)
{
	char *commands[MAX_LEN];
	char *commands_arr[MAX_LEN];
	ssize_t nread;

	while (1)
	{
		nread = read(STDIN_FILENO, commands, MAX_LEN);
		exit(EXIT_FAILURE);
		else if (nread == 0)
		{
			break;
		}
		commands[nread] = '\0';

		split_newline(commands, commands_arr);
		handle_commands_array(comands_arr);
	}
	return (0);
}
