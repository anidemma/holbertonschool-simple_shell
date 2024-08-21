#include "main.h"


/**
 * handle_command - command handler
 * @u_command: command
*/
void handle_command(char *command)
{

}









/**
 * handle_commands_arr - func for handling array of commands
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
				handle_command(command);
			}
		}
	}
}

